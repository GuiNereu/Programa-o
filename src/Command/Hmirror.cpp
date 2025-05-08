#include "Command/Hmirror.hpp"
#include "Image.hpp"
#include <sstream>
#include <algorithm>

namespace prog {
    namespace command {

        Hmirror::Hmirror() : Command("Hmirror") {}

        Hmirror::~Hmirror() {}

        Image *Hmirror::apply(Image *img) {
            int w = img->width();
            int h = img->height();

            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w / 2; ++x) {
                    std::swap(img->at(x, y), img->at(w - 1 - x, y));
                }
            }

            return img;
        }

        std::string Hmirror::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}
