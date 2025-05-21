#ifndef INVERT_HPP
#define INVERT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        // A classe InvertCommand representa um comando que inverte as cores de uma imagem
        // Cada componente RGB de cada pixel será invertido
        class InvertCommand : public Command {
        public:

            // Construtor da classe InvertCommand
            // Nenhum parâmetro é necessário, pois a operação afeta a imagem inteira
            InvertCommand();

            // Destrutor da classe InvertCommand
            ~InvertCommand();

            // Aplica a inversão de cores à imagem fornecida
            Image *apply(Image *img) override;

            // Retorna uma string que representa o comando (ex: "invert"), útil para logs e debug.
            std::string toString() const override;
        };

    }
}
#endif //INVERT_HPP
