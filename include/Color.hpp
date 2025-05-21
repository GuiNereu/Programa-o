#ifndef __prog_Color_hpp__
#define __prog_Color_hpp__

#include <iostream>


namespace prog {
    // Define um tipo auxiliar 'rgb_value'
    typedef unsigned char rgb_value;

    // Classe que representa uma cor RGB com componentes de cor vermelho, verde e azul
    class Color {
    private:
        rgb_value r;
        rgb_value g;
        rgb_value b;

    public:
        // Construtor padrão que inicializa a cor
        Color();

        // Construtor de cópia que cria uma nova cor copiando outra
        Color(const Color &c);

        // Construtor que inicializa com valores específicos de vermelho, verde e azul
        Color(rgb_value r_, rgb_value g_, rgb_value b_);

        // Métodos de acesso constantes para os componentes de cor
        rgb_value red() const;
        rgb_value green() const;
        rgb_value blue() const;

        // Métodos de acesso que permitem modificar diretamente os componentes
        rgb_value &red();
        rgb_value &green();
        rgb_value &blue();
    };
}


std::istream &operator>>(std::istream &input, prog::Color &c);

std::ostream &operator<<(std::ostream &output, const prog::Color &c);


#endif
