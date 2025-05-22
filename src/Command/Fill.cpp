#include "Command/Fill.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        // Construtor da classe Fill
        // Inicializa o comando com as coordenadas (x, y), dimensões (w, h) e a cor com a qual a área será preenchida
        Fill::Fill(int x, int y, int w, int h, Color &fill)
            : Command("Fill"), x(x), y(y), w(w), h(h), fill(fill) {}

        // Destrutor da classe Fill
        Fill::~Fill() {}


        Image *Fill::apply(Image *img) {

            // Largura e altura da imagem
            int img_w = img->width();
            int img_h = img->height();

            // Percorre a região retangular definida pelos parâmetros
            for (int dy = 0; dy < h; ++dy) {
                for (int dx = 0; dx < w; ++dx) {

                    // Posição x e y atual na imagem
                    int px = x + dx;
                    int py = y + dy;

                    // Garante que o pixel está dentro dos limites da imagem
                    if (px >= 0 && px < img_w && py >= 0 && py < img_h) {
                        img->at(px, py) = fill; // Define a cor do pixel
                    }
                }
            }

            // Retorna a imagem modificada
            return img;
        }


        // Gera uma string que representa o comando Fill e seus parâmetros
        std::string Fill::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x << " y:" << y
               << " w:" << w << " h:" << h << " fill:" << fill;
            return ss.str();
        }

    }
}