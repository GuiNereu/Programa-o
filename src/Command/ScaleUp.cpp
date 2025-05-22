#include "Command/ScaleUp.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        // Construtor da classe ScaleUp que inicializa os fatores de escala
        ScaleUp::ScaleUp(int x_factor, int y_factor)
            : Command("ScaleUp"), x_factor(x_factor), y_factor(y_factor) {}

        // Destrutor da classe ScaleUp
        ScaleUp::~ScaleUp() {}

        // Metodo que aplica a operação de escala na imagem fornecida
        Image *ScaleUp::apply(Image *img) {
            // Obtém as dimensões originais da imagem
            int old_w = img->width();
            int old_h = img->height();

            // Calcula as novas dimensões após a escala
            int new_w = old_w * x_factor;
            int new_h = old_h * y_factor;

            // Obtém a cor do pixel superior esquerdo para preencher a nova imagem
            Color fill = img->at(0, 0);

            // Cria uma nova imagem com as dimensões escaladas e preenchida com a cor obtida
            Image *scaled = new Image(new_w, new_h, fill);

            // Percorre cada pixel da imagem original
            for (int y = 0; y < old_h; ++y) {
                for (int x = 0; x < old_w; ++x) {
                    // Obtém a cor do pixel atual
                    const Color &pixel = img->at(x, y);
                    // Replica o pixel de acordo com os fatores de escala
                    for (int dy = 0; dy < y_factor; ++dy) {
                        for (int dx = 0; dx < x_factor; ++dx) {
                            // Define a cor do pixel correspondente na nova imagem
                            scaled->at(x * x_factor + dx, y * y_factor + dy) = pixel;
                        }
                    }
                }
            }

            // Libera a memória da imagem original
            delete img;
            return scaled;
        }

        // Metodo que retorna uma representação em string do comando ScaleUp
        std::string ScaleUp::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x_factor << " y:" << y_factor;
            return ss.str();
        }


    }
}