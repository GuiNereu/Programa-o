#include "Color.hpp"
#include <iostream>


using std::istream;

namespace prog {
    Color::Color() : r(0), g(0), b(0) {}

    Color::Color(const Color &other) : r(other.r), g(other.g), b(other.b) {}

    Color::Color(rgb_value r_, rgb_value g_, rgb_value b_) : r(r_), g(g_), b(b_) {}

    rgb_value Color::red() const { return r; }
    rgb_value& Color::red() { return r; }

    rgb_value Color::green() const { return g; }
    rgb_value& Color::green() { return g; }

    rgb_value Color::blue() const { return b; }
    rgb_value& Color::blue() { return b; }

}


// Use to read color values from a script file.
istream &operator>>(istream &input, prog::Color &c) {
    int r, g, b;
    input >> r >> g >> b;
    c.red() = r;
    c.green() = g;
    c.blue() = b;
    return input;
}

std::ostream &operator<<(std::ostream &output, const prog::Color &c) {
    output << (int) c.red() << ":" << (int) c.green() << ":" << (int) c.blue();
    return output;
}
