#ifndef REPLACE_HPP
#define REPLACE_HPP

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        // A classe Replace representa um comando que substitui uma cor específica por outra em toda a imagem
        class Replace : public Command {
        public:

            // Construtor da classe Replace
            // from: a cor original que deve ser substituída
            // to: a nova cor que irá substituir a cor original
            Replace(Color &from, Color &to);

            // Destrutor da classe Replace
            ~Replace();

            // Aplica a substituição na imagem fornecida
            // Todos os pixels da cor 'from' são alterados para a cor 'to'
            Image *apply(Image *img) override;

            // Retorna uma descrição textual do comando, útil para logs ou debug
            std::string toString() const override;

        private:
            Color from; // Cor a ser substituída
            Color to;   // Nova cor que será usada no lugar da original
        };

        };
    }


#endif //REPLACE_HPP
