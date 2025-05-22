#include "Command/Add.hpp"
#include "Command/Open.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include "Logger.hpp"
#include <sstream>

namespace prog {
    namespace command {

        // Construtor da classe Add
        // Inicializa os atributos filename, neutral (cor que será ignorada, como transparência) e as coordenadas (x, y) onde a imagem será colocada na imagem base
        Add::Add(const std::string &filename, const Color &neutral, int x, int y)
            : Command("Add"), filename(filename), neutral(neutral), x(x), y(y) {}

        // Destrutor da classe Add.
        Add::~Add() {}

        Image *Add::apply(Image *img) {
            // Cria um comando Open que carrega a imagem de sobreposição
            Open loader(filename);
            Image *overlay = loader.apply(nullptr);

            // Verifica se a imagem foi carregada com sucesso
            if (!overlay) {
                *Logger::err() << "Failed to load image: " << filename << "\n";
                return img;
            }

            // Obtém as dimensões da imagem de sobreposição e da imagem base
            int overlay_w = overlay->width();
            int overlay_h = overlay->height();
            int base_w = img->width();
            int base_h = img->height();

            // Percorre todos os pixels da imagem de sobreposição
            for (int i = 0; i < overlay_w; ++i) {
                for (int j = 0; j < overlay_h; ++j) {
                    Color &pixel = overlay->at(i, j);

                    // Verifica se o pixel não é igual à cor neutra
                    if (pixel.red() != neutral.red() ||
                        pixel.green() != neutral.green() ||
                        pixel.blue() != neutral.blue()) {

                        int target_x = x + i;
                        int target_y = y + j;

                        // Verifica se a posição resultante está dentro dos limites da imagem base
                        if (target_x >= 0 && target_x < base_w &&
                            target_y >= 0 && target_y < base_h) {
                            // Substitui o pixel da imagem base pelo pixel da sobreposição
                            img->at(target_x, target_y) = pixel;
                            }
                        }
                }
            }

            // Liberta a memória da imagem de sobreposição
            delete overlay;

            // Retorna a imagem modificada
            return img;
        }


        // Converte o comando para uma string descritiva, útil para logs ou debug
        std::string Add::toString() const {
            std::ostringstream ss;
            ss << name() << " file:" << filename
               << " neutral:" << neutral
               << " x:" << x << " y:" << y;
            return ss.str();
        }
    }
}
