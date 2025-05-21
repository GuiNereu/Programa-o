#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__

#include "Color.hpp"
#include <vector>

namespace prog {
    // Classe que representa uma imagem como uma matriz de pixeis coloridos
    class Image {
    private:
        int w; // Representa a largura da imagem
        int h; // Representa a altura da imagem

        // Matriz 2D de pixels (cada pixel é um objeto da classe Color)
        std::vector<std::vector<Color>> pixels;

    public:
        // Construtor: cria uma imagem com largura 'w' e altura 'h'
        // Inicializa todos os pixels com a cor 'fill' (por padrão, branco: {255, 255, 255})
        Image(int w, int h, const Color &fill = {255, 255, 255});

        // Destrutor: chamado automaticamente quando a imagem é destruída
        ~Image();

        // Retorna a largura da imagem
        int width() const;

        // Retorna a altura da imagem
        int height() const;

        // Acessa um pixel específico na posição (x, y) e retorna uma referência modificável, permitindo alterar a cor do pixel
        Color &at(int x, int y);

        // Acessa um pixel específico na posição (x, y)
        const Color &at(int x, int y) const;
    };

}
#endif
