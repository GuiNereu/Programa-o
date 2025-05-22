#include "Command/Resize.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {
    namespace command {

        // Construtor da classe Resize
        // Define a nova área da imagem a ser copiada e redimensionada
        Resize::Resize(int x, int y, int w, int h)
            : Command("Resize"), x(x), y(y), w(w), h(h) {}

        // Destrutor da classe Resire
        Resize::~Resize() {}


        Image *Resize::apply(Image *img) {
            int img_w = img->width();
            int img_h = img->height();

            // Usa o pixel no canto superior esquerdo da imagem original como cor de preenchimento padrão
            Color fill = img->at(0, 0);

            // Cria uma nova imagem com as dimensões especificadas e preenchida com a cor default
            Image *resized = new Image(w, h, fill);

            // Copia os pixels da imagem original para a nova imagem
            for (int j = 0; j < h; ++j) {
                for (int i = 0; i < w; ++i) {
                    int src_x = x + i;
                    int src_y = y + j;

                    // Verifica se o pixel de origem está dentro dos limites da imagem original
                    if (src_x >= 0 && src_x < img_w && src_y >= 0 && src_y < img_h) {
                        resized->at(i, j) = img->at(src_x, src_y);
                    }
                    // Caso contrário, o pixel já está preenchido com a cor 'fill'
                }
            }

            // Libera a memória da imagem antiga
            delete img;
            return resized;
        }


        // Retorna uma string com os parâmetros usados no comando
        std::string Resize::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x << " y:" << y << " w:" << w << " h:" << h;
            return ss.str();
        }

    }
}
