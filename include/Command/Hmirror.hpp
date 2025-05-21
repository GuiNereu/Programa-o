#ifndef HMIRROR_HPP
#define HMIRROR_HPP

#include "Command.hpp"

namespace prog {
    namespace command {

        // A classe Hmirror representa um comando que espelha horizontalmente uma imagem
        class Hmirror : public Command {
        public:

            // Construtor da classe Hmirror
            // Nenhum parâmetro é necessário porque o espelhamento horizontal aplica-se à imagem inteira
            Hmirror();

            // Destrutor da classe Hmirror
            ~Hmirror();

            // Aplica o espelhamento horizontal à imagem fornecida.
            // Isso inverte os pixels da esquerda para a direita, como se a imagem fosse refletida num espelho vertical
            Image *apply(Image *img) override;

            // Retorna uma string representando o comando, útil para logs ou debug
            std::string toString() const override;
        };
    }
}

#endif //HMIRROR_HPP
