#include "Command/Invert.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        // Construtor da classe InvertCommand
        // Inicializa o comando com o nome "Invert"
        InvertCommand::InvertCommand() : Command("Invert") {}

        // Destrutor da classe InvertCommand
        InvertCommand::~InvertCommand() {}


        Image *InvertCommand::apply(Image *img) {
            if (!img) return nullptr; // Verifica se a imagem é válida

            // Obtém a largura e altura da imagem
            int w = img->width();
            int h = img->height();

            // Percorre todos os pixels da imagem
            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w; ++x) {
                    Color &pixel = img->at(x, y);

                    // Inverte cada componente de cor (subtrai de 255)
                    // Isso cria o "negativo" da imagem
                    pixel.red() = 255 - pixel.red();
                    pixel.green() = 255 - pixel.green();
                    pixel.blue() = 255 - pixel.blue();
                }
            }

            return img; // Retorna a imagem modificada
        }


        // Retorna uma string com o nome do comando, útil para logs ou debug
        std::string InvertCommand::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}