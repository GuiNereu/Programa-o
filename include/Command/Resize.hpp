#ifndef RESIZE_HPP
#define RESIZE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        // A classe Resize representa um comando que redimensiona a imagem, cortando-a ou expandindo-a a partir de uma posição inicial (x, y) e ajustando para novas dimensões (w, h)
        class Resize : public Command {
        public:

            // Construtor da classe Resize
            // x, y: coordenadas da posição inicial da nova imagem (origem do recorte ou inserção)
            // w, h: novas dimensões (largura e altura) desejadas para a imagem
            Resize(int x, int y, int w, int h);

            // Destrutor da classe Resize
            ~Resize();

            // Aplica o redimensionamento à imagem fornecida
            // Cria uma nova imagem com as dimensões (w, h), copiando a partir da posição (x, y) da imagem original
            // Se a nova imagem for maior, pode preencher áreas vazias com uma cor neutra (dependendo da implementação)
            Image *apply(Image *img) override;

            // Retorna uma string representando o comando, útil para logs ou debug
            std::string toString() const override;

        private:
            // Coordenadas x e y de origem
            int x; //
            int y; //

            // Nova largura e altura da imagem
            int w;
            int h;
        };
    }
}

#endif //RESIZE_HPP
