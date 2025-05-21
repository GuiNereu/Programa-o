#ifndef MOVE_HPP
#define MOVE_HPP

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        // A classe Move representa um comando que move (desloca) a imagem na horizontal e/ou vertical
        class Move : public Command {
        public:

            // Construtor da classe Move
            // dx: deslocamento horizontal (positivo para a direita, negativo para a esquerda)
            // dy: deslocamento vertical (positivo para baixo, negativo para cima)
            Move(int dx, int dy);

            // Destrutor da classe Move
            ~Move();

            // Aplica o deslocamento à imagem
            // Os pixels são movidos e as posições "vazias" podem ser preenchidas com uma cor neutra dependendo da implementação
            Image *apply(Image *img) override;

            // Retorna uma string representando o comando (ex: "move 10 -5"), útil para logs ou debug.
            std::string toString() const override;

        private:
            int dx; // Deslocamento horizontal
            int dy; // Deslocamento vertical
        };

    }
}

#endif //MOVE_HPP
