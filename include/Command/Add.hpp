#ifndef ADD_HPP
#define ADD_HPP

#include "Command.hpp"
#include "Color.hpp"
#include <string>

namespace prog {
    namespace command {
        class Add : public Command {
        public:
            // Construtor: recebe os parâmetros necessários para aplicar o comando
            // filename: nome do ficheiro da imagem a adicionar
            // neutral: cor considerada como transparente ao adicionar a imagem
            // x, y: coordenadas onde a imagem será colocada
            Add(const std::string &filename, const Color &neutral, int x, int y);

            // Destrutor da classe Add
            ~Add();

            // Retorna um ponteiro para a nova imagem modificada e aplica o comando à imagem dada
            Image *apply(Image *img) override;
            std::string toString() const override;

        private:
            std::string filename;
            Color neutral; // Cor neutra (transparente): pixels com essa cor não são copiados
            int x;
            int y;
        };
    }
}

#endif //ADD_HPP
