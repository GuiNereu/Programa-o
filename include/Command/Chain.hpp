#ifndef CHAIN_HPP
#define CHAIN_HPP

#include "Command.hpp"
#include <set>
#include <vector>
#include <string>

namespace prog {
    namespace command {

        // Classe Chain: representa um comando que aplica uma sequência de comandos a uma imagem
        class Chain : public Command {
        public:
            // Construtor: recebe os parâmetros necessários para aplicar o comando
            // - files: vetor de nomes de arquivos contendo comandos a serem executados em sequência
            // - seen: conjunto de arquivos já processados (usado para evitar recursão infinita)
            Chain(const std::vector<std::string>& files, std::set<std::string> seen = {});

            // Destrutor da classe chain
            ~Chain();

            // Aplica todos os comandos listados nos arquivos sobre a imagem original
            // Retorna um ponteiro para a nova imagem modificada
            Image* apply(Image* img) override;

            // Retorna uma representação em texto do comando Chain (ex: para logs ou debug)
            std::string toString() const override;

        private:
            // Lista de arquivos que contêm comandos a serem aplicados
            std::vector<std::string> files;

            // Conjunto de arquivos já vistos, para evitar loops recursivos
            std::set<std::string> seen;
        };
    }
}

#endif //CHAIN_HPP
