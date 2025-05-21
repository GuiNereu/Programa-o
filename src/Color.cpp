#include "Color.hpp"
#include <iostream>


using std::istream;

namespace prog {
    // inicializa a cor como preto (0,0,0)
    Color::Color() : r(0), g(0), b(0) {}

    // copia os valores de outro objeto Color
    Color::Color(const Color &other) : r(other.r), g(other.g), b(other.b) {}

    // inicializa a cor com valores específicos de R, G e B
    Color::Color(rgb_value r_, rgb_value g_, rgb_value b_) : r(r_), g(g_), b(b_) {}

    // Retorna o valor dos componentes vermelho, verde e azul (apenas leitura) e retorna lhes uma referência (permite modificar)
    rgb_value Color::red() const { return r; }
    rgb_value& Color::red() { return r; }

    rgb_value Color::green() const { return g; }
    rgb_value& Color::green() { return g; }

    rgb_value Color::blue() const { return b; }
    rgb_value& Color::blue() { return b; }

}


// Função para ler valores RGB de um fluxo de entrada (como um arquivo)
istream &operator>>(istream &input, prog::Color &c) {
    int r, g, b;
    // Lê três inteiros do fluxo
    input >> r >> g >> b;
    // Atribui os valores lidos aos componentes da cor
    c.red() = r;
    c.green() = g;
    c.blue() = b;
    // Retorna o fluxo
    return input;
}

// Função para imprimir uma cor no formato "R:G:B"
std::ostream &operator<<(std::ostream &output, const prog::Color &c) {
    output << (int) c.red() << ":" << (int) c.green() << ":" << (int) c.blue();
    // Retorna o fluxo
    return output;
}
