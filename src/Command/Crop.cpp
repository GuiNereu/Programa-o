#include "Command/Crop.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        // Construtor da classe Crop
        // Recebe as coordenadas (x, y) do canto superior esquerdo da área a recortar e as dimensões (largura w e altura h) do retângulo de recorte
        Crop::Crop(int x, int y, int w, int h)
            : Command("Crop"), x(x), y(y), w(w), h(h) {}

        // Destrutor da classe Crop
        Crop::~Crop() {}


        Image *Crop::apply(Image *img) {

            // Largura e altura da imagem original
            int img_w = img->width();
            int img_h = img->height();

            // Cria uma nova imagem com as dimensões do recorte
            Image *cropped = new Image(w, h);

            // Copia os pixels da região especificada da imagem original para a nova imagem
            for (int j = 0; j < h; ++j) {
                for (int i = 0; i < w; ++i) {

                    // Coordenada X e Y no original
                    int src_x = x + i;
                    int src_y = y + j;

                    // Verifica se o pixel está dentro dos limites da imagem original
                    if (src_x >= 0 && src_x < img_w && src_y >= 0 && src_y < img_h) {
                        cropped->at(i, j) = img->at(src_x, src_y); // Copia o pixel
                    }
                }
            }

            delete img; // Liberta a memória da imagem original
            return cropped; // Retorna a nova imagem recortada
        }


        // Gera uma string com a descrição do comando Crop e seus parâmetros
        std::string Crop::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x << " y:" << y << " w:" << w << " h:" << h;
            return ss.str();
        }

    }
}