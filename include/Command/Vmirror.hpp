#ifndef VMIRROR_HPP
#define VMIRROR_HPP

#include "Command.hpp"

namespace prog {
    namespace command {

        // A classe Vmirror representa um comando que espelha verticalmente uma imagem
        class Vmirror : public Command {
        public:

            // Construtor da classe Vmirror
            // Nenhum parâmetro é necessário porque o espelhamento vertical aplica-se à imagem inteira
            Vmirror();

            // Destrutor da classe Vmirror
            ~Vmirror();

            // Aplica o espelhamento vertical à imagem fornecida.
            // Isso inverte os pixels de cima para baixo, como se a imagem fosse refletida num espelho horizontal
            Image *apply(Image *img) override;

            // Retorna uma string representando o comando, útil para logs ou debug
            std::string toString() const override;
        };
    }
}

#endif //VMIRROR_HPP
