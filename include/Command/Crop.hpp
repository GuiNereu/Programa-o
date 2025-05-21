#ifndef CROP_HPP
#define CROP_HPP

#include "Command.hpp"

namespace prog {
    namespace command {

        // A classe Crop representa um comando que recorta uma parte da imagem
        class Crop : public Command {
        public:
            // Construtor da classe Crop
            // Recebe as coordenadas (x, y) do canto superior esquerdo da área a ser recortada
            // e a largura (w) e altura (h) dessa área
            Crop(int x, int y, int w, int h);

            // Destrutor da classe crop
            ~Crop();

            // Metodo que aplica o recorte à imagem fornecida.
            // Retorna um ponteiro para a nova imagem resultante, contendo apenas a área recortada.
            Image *apply(Image *img) override;

            // Retorna uma string representando este comando
            // útil para fins de debug ou para imprimir a sequência de comandos
            std::string toString() const override;

        private:

            // Coordenadas x e y do ponto inicial do recorte
            int x;
            int y;

            // Largura e altura da região a ser recortada
            int w;
            int h;
        };
    }
}

#endif //CROP_HPP
