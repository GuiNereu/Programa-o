#ifndef TOGRAYSCALE_HPP
#define TOGRAYSCALE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        // A classe ToGrayScale representa um comando que converte uma imagem colorida para tons de cinza
        class ToGrayScale : public Command {
        public:

            // Construtor padrão da classe ToGrayScale
            // Não precisa de parâmetros, pois a operação aplica-se à imagem inteira
            ToGrayScale();

            // Destrutor da classe ToGrayScale
            ~ToGrayScale();

            // Aplica a conversão para escala de cinza à imagem fornecida
            // Cada pixel terá seu valor RGB convertido em um tom de cinza, geralmente pela média ponderada dos canais
            Image *apply(Image *img) override;

            // Retorna uma string representando o comando, útil para logs ou debug
            std::string toString() const override;
        };

    }
}

#endif //TOGRAYSCALE_HPP
