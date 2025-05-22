#include "ScrimParser.hpp"
#include "Command/Blank.hpp"
#include "Command/Save.hpp"
#include "Command/Open.hpp"
#include "Command/Invert.hpp"
#include "Command/ToGrayScale.hpp"
#include "Command/Replace.hpp"
#include "Command/Fill.hpp"
#include "Command/Hmirror.hpp"
#include "Command/Vmirror.hpp"
#include "Command/Add.hpp"
#include "Command/Move.hpp"
#include "Command/Slide.hpp"
#include "Command/Crop.hpp"
#include "Command/Resize.hpp"
#include "Command/RotateLeft.hpp"
#include "Command/RotateRight.hpp"
#include "Command/ScaleUp.hpp"
#include "Command/Chain.hpp"
#include "Logger.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>

using std::ifstream;
using std::istream;
using std::string;
using std::vector;
using std::set;

namespace prog {

    ScrimParser::ScrimParser() {}

    ScrimParser::~ScrimParser() {}

    Scrim* ScrimParser::parseScrim(istream& input) {
        vector<Command*> commands;

        string command_name;
        while (input >> command_name) {
            Command* command = parse_command(command_name, input);

            if (command == nullptr) {
                for (Command* allocated_command : commands) {
                    delete allocated_command;
                }

                *Logger::err() << "Error while parsing command\n";
                return nullptr;
            }

            commands.push_back(command);
        }

        return new Scrim(commands);
    }

    Scrim* ScrimParser::parseScrim(const string& filename) {
        ifstream in(filename);
        return parseScrim(in);
    }

    vector<Command*> ScrimParser::parse(const string& filename, set<string>& seen) {
        vector<Command*> result;

        if (seen.count(filename)) {
            *Logger::err() << "Ignoring recursive chain call to '" << filename << "'\n";
            return result;
        }

        seen.insert(filename);

        ifstream in(filename);
        if (!in) {
            *Logger::err() << "Could not open file '" << filename << "'\n";
            return result;
        }

        string command_name;
        while (in >> command_name) {
            if (command_name == "chain") {
                string nested;
                std::vector<std::string> chain_files;

                std::string line;
                while (std::getline(in, line)) {
                    std::istringstream ss(line);
                    std::string nested;
                    ss >> nested;

                    if (nested.empty()) continue;
                    if (nested == "end") break;
                    chain_files.push_back(nested);
                }

                Command* chain_cmd = new command::Chain(chain_files, seen);
                result.push_back(chain_cmd);
            } else if (command_name == "blank" || command_name == "open" || command_name == "save") {
                string dummy_line;
                std::getline(in, dummy_line); // Skip the rest of the line
                *Logger::out() << "Ignoring command '" << command_name << "' in file '" << filename << "'\n";
            } else {
                Command* cmd = parse_command(command_name, in);
                if (cmd != nullptr) {
                    result.push_back(cmd);
                } else {
                    *Logger::err() << "Error parsing command in file '" << filename << "'\n";
                }
            }
        }

        return result;
    }

    // Metodo que interpreta um nome de comando e os parâmetros subsequentes, e cria o objeto Command correspondente
    Command* ScrimParser::parse_command(string command_name, istream& input) {

        // Comando "blank": cria uma imagem em branco com largura, altura e cor especificadas
        if (command_name == "blank") {
            int w, h;
            Color fill;
            input >> w >> h >> fill;
            return new command::Blank(w, h, fill);
        }

        // Comando "save": salva a imagem atual num arquivo
        if (command_name == "save") {
            string filename;
            input >> filename;
            return new command::Save(filename);
        }

        // Comando "open": abre uma imagem de um arquivo
        if (command_name == "open") {
            string filename;
            input >> filename;
            return new command::Open(filename);
        }

        // Comando "invert": inverte as cores da imagem
        if (command_name == "invert") {
            return new command::InvertCommand();
        }

        // Comando "to_gray_scale": converte a imagem para tons de cinza
        if (command_name == "to_gray_scale") {
            return new command::ToGrayScale();
        }

        // Comando "replace": substitui uma cor específica por outra
        if (command_name == "replace") {
            Color from, to;
            input >> from >> to;
            return new command::Replace(from, to);
        }

        // Comando "fill": preenche uma área retangular da imagem com uma cor
        if (command_name == "fill") {
            int x, y, w, h;
            Color fill;
            input >> x >> y >> w >> h >> fill;
            return new command::Fill(x, y, w, h, fill);
        }

        // Comando "h_mirror": espelha a imagem horizontalmente
        if (command_name == "h_mirror") {
            return new command::Hmirror();
        }

        // Comando "v_mirror": espelha a imagem verticalmente
        if (command_name == "v_mirror") {
            return new command::Vmirror();
        }

        // Comando "add": adiciona uma imagem por cima da atual em determinada posição, com uma cor neutra
        if (command_name == "add") {
            string filename;
            Color neutral;
            int x, y;
            input >> filename >> neutral >> x >> y;
            return new command::Add(filename, neutral, x, y);
        }

        // Comando "move": move os pixels da imagem em dx, dy (deslocamento)
        if (command_name == "move") {
            int dx, dy;
            input >> dx >> dy;
            return new command::Move(dx, dy);
        }

        // Comando "slide": desliza a imagem em dx, dy com wrap-around (pixels que saem voltam do outro lado)
        if (command_name == "slide") {
            int dx, dy;
            input >> dx >> dy;
            return new command::Slide(dx, dy);
        }

        // Comando "crop": recorta uma área da imagem
        if (command_name == "crop") {
            int x, y, w, h;
            input >> x >> y >> w >> h;
            return new command::Crop(x, y, w, h);
        }

        // Comando "resize": redimensiona a imagem a partir de uma subárea
        if (command_name == "resize") {
            int x, y, w, h;
            input >> x >> y >> w >> h;
            return new command::Resize(x, y, w, h);
        }

        // Comando "rotate_left": gira a imagem 90° para a esquerda
        if (command_name == "rotate_left") {
            return new command::RotateLeft();
        }

        // Comando "rotate_right": gira a imagem 90° para a direita
        if (command_name == "rotate_right") {
            return new command::RotateRight();
        }

        // Comando "scaleup": aumenta a imagem proporcionalmente por fatores x e y
        if (command_name == "scaleup") {
            int x, y;
            input >> x >> y;
            return new command::ScaleUp(x, y);
        }

        // Comando "chain": aplica uma sequência de comandos a partir de vários arquivos
        if (command_name == "chain") {
            vector<string> filenames;
            string filename;

            // Lê nomes de arquivos até encontrar a palavra "end"
            while (input >> filename && filename != "end") {
                filenames.push_back(filename);
            }
            return new command::Chain(filenames);
        }

        // Caso o comando não seja reconhecido, registra um erro e retorna nullptr
        *Logger::err() << "Command not recognized: '" + command_name + "'\n";
        return nullptr;
    }

}