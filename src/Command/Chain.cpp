#include "Command/Chain.hpp"
#include "ScrimParser.hpp"
#include "Logger.hpp"
#include <fstream>
#include <sstream>

namespace prog {
    namespace command {

        // Construtor da classe Chain
        // Recebe uma lista de ficheiros e um conjunto de nomes já vistos
        Chain::Chain(const std::vector<std::string>& files, std::set<std::string> seen)
            : Command("Chain"), files(files), seen(seen) {}

        // Destrutor da classe Chain
        Chain::~Chain() {}


        Image* Chain::apply(Image* img) {
            for (const std::string& filename : files) {

                // Ignorar caso ficheiro já tenha sido processado (para evitar ciclos recursivos)
                if (seen.count(filename)) {
                    *Logger::err() << "Skipping recursive chain file: " << filename << "\n";
                    continue;
                }

                // Analisa o script (ficheiro de comandos)
                ScrimParser parser;
                std::vector<Command*> cmds = parser.parse(filename, seen);

                // Marca o ficheiro como visto para evitar chamadas recursivas no futuro
                seen.insert(filename);

                std::vector<Command*> filtered;

                // Filtra comandos, removendo o comando "save" (não deve ser executado em cadeia)
                for (Command* cmd : cmds) {
                    std::string n = cmd->name();
                    if (n == "save") {
                        delete cmd; // Liberta memória
                    } else {
                        filtered.push_back(cmd);
                    }
                }

                // Cria um novo "Scrim" com os comandos filtrados e executa-os na imagem atual
                Scrim sub_scrim(filtered);
                img = sub_scrim.run(img);
            }

            // Retorna a imagem resultante após aplicar todos os scripts
            return img;
        }


        // Representa o comando como string, listando os nomes dos scripts encadeados
        std::string Chain::toString() const {
            std::ostringstream ss;
            ss << name() << " [";
            for (const std::string& f : files) {
                ss << f << " ";
            }
            ss << "]";
            return ss.str();
        }

    }
}
