#include "Command/RotateRight.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        // Construtor da classe RotateRight
        // Define o nome do comando como "RotateRight"
        RotateRight::RotateRight() : Command("RotateRight") {}

        // Destrutor da classe RotateRight
        RotateRight::~RotateRight() {}

        Image *RotateRight::apply(Image *img) {
            int old_w = img->width();
            int old_h = img->height();

            // Usa o pixel do canto superior esquerdo como cor de preenchimento padrão
            Color fill = img->at(0, 0);

            // Cria nova imagem com largura e altura trocadas (rotacionada 90º para a direita)
            Image *rotated = new Image(old_h, old_w, fill);

            // Realiza a rotação: (x, y) → (old_h - 1 - y, x)
            for (int y = 0; y < old_h; ++y) {
                for (int x = 0; x < old_w; ++x) {
                    rotated->at(old_h - 1 - y, x) = img->at(x, y);
                }
            }

            // Libera a imagem original da memória
            delete img;
            return rotated;
        }


        // Retorna o nome do comando como string
        std::string RotateRight::toString() const {
            return name();
        }
    }
}