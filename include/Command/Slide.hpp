#ifndef SLIDE_HPP
#define SLIDE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        // A classe Slide representa um comando que desliza a imagem, movendo todos os pixels em dx (horizontal) e dy (vertical) com rotação dos que saem da borda
        class Slide : public Command {
        public:

            // Construtor da classe Slide
            // dx: deslocamento horizontal (positivo para a direita, negativo para a esquerda)
            // dy: deslocamento vertical (positivo para baixo, negativo para cima)
            // Os pixels que "saem" de um lado reaparecem do lado oposto
            Slide(int dx, int dy);

            // Destrutor da classe Slide
            ~Slide();

            // Aplica o deslizamento à imagem, deslocando todos os pixels de forma cíclica
            Image *apply(Image *img) override;

            // Retorna uma string representando o comando, útil para logs ou debug
            std::string toString() const override;

        private:

            // Deslocamento horizontal e vertical
            int dx;
            int dy;
        };
    }
}

#endif //SLIDE_HPP
