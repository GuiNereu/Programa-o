#include "Command/Slide.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        // Construtor da classe Slide que inicializa os deslocamentos em x e y
        Slide::Slide(int dx, int dy) : Command("Slide"), dx(dx), dy(dy) {}

        // Destrutor da classe Slide
        Slide::~Slide() {}

        // Aplica o comando de deslizamento à imagem
        Image *Slide::apply(Image *img) {
            // Largura e altura da imagem
            int w = img->width();
            int h = img->height();

            // Cria uma nova imagem com as mesmas dimensões da original
            Image *result = new Image(w, h);

            // Percorre todos os pixels da imagem original
            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w; ++x) {
                    // Calcula as novas posições aplicando o deslocamento
                    int new_x = (x + dx) % w;
                    int new_y = (y + dy) % h;

                    // Garante que os índices estejam sempre positivos (corrige se forem negativos)
                    if (new_x < 0) new_x += w;
                    if (new_y < 0) new_y += h;

                    // Copia o pixel da posição original para a nova posição na imagem resultante
                    result->at(new_x, new_y) = img->at(x, y);
                }
            }

            delete img;      // Libera a memória da imagem original
            return result;
        }

        // Retorna uma representação textual do comando, útil para debug/log
        std::string Slide::toString() const {
            std::ostringstream ss;
            ss << name() << " dx:" << dx << " dy:" << dy;
            return ss.str();
        }


    }
}