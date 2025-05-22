#include "Command/ToGrayScale.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        // Construtor da classe ToGrayScale
        ToGrayScale::ToGrayScale() : Command("ToGrayScale") {}

        // Destrutor da classe
        ToGrayScale::~ToGrayScale() {}

        // Metodo que aplica o efeito de escala de cinza à imagem
        Image *ToGrayScale::apply(Image *img) {
            // Verifica se a imagem é nula (proteção contra ponteiros inválidos)
            if (!img) return nullptr;

            // Largura e altura da imagem
            int w = img->width();
            int h = img->height();

            // Percorre todos os pixels da imagem
            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w; ++x) {
                    Color &pixel = img->at(x, y);  // Acessa o pixel na posição (x, y)

                    // Calcula a média dos valores RGB para obter a intensidade de cinza
                    int v = (pixel.red() + pixel.green() + pixel.blue()) / 3;

                    // Define todos os canais de cor (R, G, B) com o valor médio calculado
                    pixel.red() = pixel.green() = pixel.blue() = static_cast<rgb_value>(v);
                }
            }

            // Retorna a imagem modificada
            return img;
        }

        // Retorna uma string com o nome do comando, útil para logs ou debug
        std::string ToGrayScale::toString() const {
            std::ostringstream ss;
            ss << name();  // O nome foi definido como "ToGrayScale"
            return ss.str();
        }
    }
}