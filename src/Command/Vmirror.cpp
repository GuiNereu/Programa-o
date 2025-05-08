#include "Command/Vmirror.hpp"
#include "Image.hpp"
#include <sstream>
#include <algorithm>

namespace prog {
    namespace command {

        Vmirror::Vmirror() : Command("Vmirror") {}

        Vmirror::~Vmirror() {}

        Image *Vmirror::apply(Image *img) {
            int w = img->width();
            int h = img->height();

            for (int x = 0; x < w; ++x) {
                for (int y = 0; y < h / 2; ++y) {
                    std::swap(img->at(x, y), img->at(x, h - 1 - y));
                }
            }

            return img;
        }

        std::string Vmirror::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}
