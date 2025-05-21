#ifndef ROTATERIGHT_HPP
#define ROTATERIGHT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        // A classe RotateRight representa um comando que rotaciona a imagem 90 graus para a direita
        class RotateRight : public Command {
        public:

            // Construtor da classe RotateRight
            // Não requer parâmetros, pois a operação é sempre uma rotação fixa de 90° para a direita
            RotateRight();

            // Destrutor da classe RotateRight
            ~RotateRight();

            // Aplica a rotação de 90 graus para a direita à imagem fornecida
            // A imagem resultante terá altura e largura trocadas
            Image *apply(Image *img) override;

            // Retorna uma string representando o comando, útil para logs ou debug
            std::string toString() const override;
        };
    }
}

#endif //ROTATERIGHT_HPP
