#include "Command/Vmirror.hpp"
#include "Image.hpp"
#include <sstream>
#include <algorithm>

namespace prog {
    namespace command {

        // Construtor da classe Vmirror, define o nome do comando como "Vmirror"
        Vmirror::Vmirror() : Command("Vmirror") {}

        // Destrutor da classe Vmirror
        Vmirror::~Vmirror() {}

        // Metodo que aplica o espelhamento vertical à imagem
        Image *Vmirror::apply(Image *img) {

            // Largura e altura da imagem
            int w = img->width();
            int h = img->height();

            // Percorre cada coluna da imagem
            for (int x = 0; x < w; ++x) {
                // Em cada coluna, percorre até a metade da altura
                for (int y = 0; y < h / 2; ++y) {
                    // Troca os pixels do topo com os do fundo, efetivamente espelhando verticalmente
                    std::swap(img->at(x, y), img->at(x, h - 1 - y));
                }
            }

            // Retorna a imagem modificada
            return img;
        }

        // Retorna uma string representando o nome do comando (para logs ou debug)
        std::string Vmirror::toString() const {
            std::ostringstream ss;
            ss << name();  // Retorna "Vmirror"
            return ss.str();
        }


    }
}
