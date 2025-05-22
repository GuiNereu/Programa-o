#include "Command/Replace.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        // Construtor da classe Replace
        // Recebe duas cores: a cor a ser substituída (from) e a nova cor (to)
        Replace::Replace(Color &from, Color &to)
            : Command("Replace"), from(from), to(to) {}

        // Destrutor da classe Replace
        Replace::~Replace() {}


        Image *Replace::apply(Image *img) {
            int w = img->width();
            int h = img->height();

            // Percorre todos os pixels da imagem
            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w; ++x) {
                    Color &c = img->at(x, y);

                    // Se o pixel for igual à cor 'from', substitui pela cor 'to'
                    if (c.red() == from.red() &&
                        c.green() == from.green() &&
                        c.blue() == from.blue()) {
                        c = to;
                        }
                }
            }

            return img; // Retorna a imagem modificada
        }


        // Retorna uma string com a descrição do comando, incluindo as cores envolvidas
        std::string Replace::toString() const {
            std::ostringstream ss;
            ss << name() << " from:" << from << " to:" << to;
            return ss.str();
        }

    }
}