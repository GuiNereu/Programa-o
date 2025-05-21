#ifndef ROTATELEFT_HPP
#define ROTATELEFT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {

        // A classe RotateLeft representa um comando que rotaciona a imagem 90 graus para a esquerda
        class RotateLeft : public Command {
        public:

            // Construtor da classe RotateLeft
            // Não requer parâmetros, pois a operação é sempre uma rotação fixa de 90° para a esquerda
            RotateLeft();

            // Destrutor da classe RotateLeft
            ~RotateLeft();

            // Aplica a rotação de 90 graus para a esquerda à imagem fornecida
            // A imagem resultante terá altura e largura trocadas
            Image *apply(Image *img) override;

            // Retorna uma string representando o comando, útil para logs ou debug
            std::string toString() const override;
        };

    }
}

#endif //ROTATELEFT_HPP
