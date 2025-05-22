#include "Command/RotateLeft.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        // Construtor da classe RotateLeft
        // Define o nome do comando como "RotateLeft"
        RotateLeft::RotateLeft() : Command("RotateLeft") {}

        // Destrutor da classe RotateLeft
        RotateLeft::~RotateLeft() {}


        Image *RotateLeft::apply(Image *img) {
            int old_w = img->width();
            int old_h = img->height();

            // Usa o pixel do canto superior esquerdo da imagem original como cor de preenchimento
            Color fill = img->at(0, 0);

            // Cria nova imagem com largura e altura trocadas (rotação 90º à esquerda)
            Image *rotated = new Image(old_h, old_w, fill);

            // Realiza a rotação: (x, y) → (y, old_w - 1 - x)
            for (int y = 0; y < old_h; ++y) {
                for (int x = 0; x < old_w; ++x) {
                    rotated->at(y, old_w - 1 - x) = img->at(x, y);
                }
            }

            // Libera memória da imagem original
            delete img;
            return rotated;
        }


        // Retorna o nome do comando como string
        std::string RotateLeft::toString() const {
            return name();
        }

    }
}