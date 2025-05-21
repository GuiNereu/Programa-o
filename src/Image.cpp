#include "Image.hpp"

namespace prog {
    // Construtor da classe Image
    // Inicializa a imagem com largura 'w' e altura 'h'
    // Preenche todos os pixels com a cor 'fill'
    Image::Image(int w, int h, const Color &fill) : w(w), h(h), pixels(h, std::vector<Color>(w, fill)) {}

    // Destrutor da classe Image
    Image::~Image() {}

    // Retorna a largura da imagem
    int Image::width() const {
        return w;
    }

    // Retorna a altura da imagem
    int Image::height() const {
        return h;
    }

    // Acessa e retorna uma referência modificável ao pixel na posição (x, y)
    // Permite alterar a cor do pixel
    Color &Image::at(int x, int y) {
        return pixels[y][x];
    }

    // Acessa e retorna uma referência constante ao pixel na posição (x, y)
    // Permite alterar a cor do pixel
    const Color &Image::at(int x, int y) const {
        return pixels[y][x];
    }
}
