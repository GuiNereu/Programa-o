#include "Command/Hmirror.hpp"
#include "Image.hpp"
#include <sstream>
#include <algorithm>

namespace prog {
    namespace command {

        // Construtor da classe Hmirror
        // Define o nome do comando como "Hmirror"
        Hmirror::Hmirror() : Command("Hmirror") {}

        // Destrutor da classe Hmirror
        Hmirror::~Hmirror() {}


        Image *Hmirror::apply(Image *img) {
            int w = img->width();  // Largura da imagem
            int h = img->height(); // Altura da imagem

            // Percorre cada linha da imagem
            for (int y = 0; y < h; ++y) {
                // Para cada linha, troca os pixels da esquerda com os da direita
                for (int x = 0; x < w / 2; ++x) {
                    std::swap(img->at(x, y), img->at(w - 1 - x, y));
                }
            }

            // Retorna a imagem modificada
            return img;
        }


        // Retorna uma string com o nome do comando, útil para debug ou logs
        std::string Hmirror::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}
