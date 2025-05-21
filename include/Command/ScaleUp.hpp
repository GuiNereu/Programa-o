#ifndef SCALEUP_HPP
#define SCALEUP_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        // A classe ScaleUp representa um comando que amplia o tamanho da imagem, multiplicando as suas dimensões por fatores inteiros em largura e altura.
        class ScaleUp : public Command {
        public:

            // Construtor da classe ScaleUp
            // x_factor: fator de escala na direção horizontal (largura)
            // y_factor: fator de escala na direção vertical (altura)
            ScaleUp(int x_factor, int y_factor);

            // Destrutor da classe ScaleUp
            ~ScaleUp();

            // Aplica o aumento de escala à imagem fornecida
            // A nova imagem terá dimensões (largura * x_factor, altura * y_factor), com os pixels replicados para preencher a nova área
            Image *apply(Image *img) override;

            // Retorna uma descrição textual do comando, útil para logs ou debug
            std::string toString() const override;

        private:

            // Fator de escala horizontal e vertical
            int x_factor;
            int y_factor;
        };

    }
}

#endif //SCALEUP_HPP
