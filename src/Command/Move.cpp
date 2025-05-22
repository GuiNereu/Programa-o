#include "Command/Move.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {
    namespace command {

        // Construtor da classe Move
        // Inicializa com os deslocamentos horizontais (dx) e verticais (dy)
        Move::Move(int dx, int dy) : Command("Move"), dx(dx), dy(dy) {}

        // Destrutor da classe Move
        Move::~Move() {}


        Image *Move::apply(Image *img) {
            int w = img->width();
            int h = img->height();

            // Cria uma nova imagem com fundo branco (255, 255, 255)
            Image *result = new Image(w, h, Color(255, 255, 255));

            // Percorre todos os pixels da imagem original
            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w; ++x) {
                    int new_x = x + dx;
                    int new_y = y + dy;

                    // Copia o pixel apenas se o novo local estiver dentro dos limites da imagem
                    if (new_x < w && new_y < h) {
                        result->at(new_x, new_y) = img->at(x, y);
                    }
                }
            }

            delete img; // Retorna a imagem original
            return result; // Retorna a imagem deslocada
        }


        // Retorna uma representação em string do comando, útil para logs/debug
        std::string Move::toString() const {
            std::ostringstream ss;
            ss << name() << " dx:" << dx << " dy:" << dy;
            return ss.str();
        }

    }
}