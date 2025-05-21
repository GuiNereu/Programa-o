#ifndef FILL_HPP
#define FILL_HPP

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {

        // A classe Fill representa um comando que preenche uma região retangular da imagem com uma cor específica
        class Fill : public Command {

        // Construtor da classe Fill
        // (x, y): coordenadas do canto superior esquerdo da região a ser preenchida
        // (w, h): largura e altura da região
        // fill: cor que será usada para preencher a região
        public:
            Fill(int x, int y, int w, int h, Color &fill);

            // Destrutor da classe fill
            ~Fill();

            // Preenche a área (x, y, w, h) com a cor armazenada
            Image *apply(Image *img) override;

            // Retorna uma descrição textual do comando
            std::string toString() const override;

        private:
            // Coordenadas e dimensões da área a ser preenchida
            int x, y, w, h;

            // Cor usada para preencher a área
            Color fill;
        };
    }
}

#endif //FILL_HPP
