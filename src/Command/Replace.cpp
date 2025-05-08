#include "Command/Replace.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Replace::Replace(Color &from, Color &to)
            : Command("Replace"), from(from), to(to) {}

        Replace::~Replace() {}

        Image *Replace::apply(Image *img) {
            int w = img->width();
            int h = img->height();

            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w; ++x) {
                    Color &c = img->at(x, y);
                    if (c.red() == from.red() &&
                        c.green() == from.green() &&
                        c.blue() == from.blue()) {
                        c = to;
                        }
                }
            }

            return img;
        }

        std::string Replace::toString() const {
            std::ostringstream ss;
            ss << name() << " from:" << from << " to:" << to;
            return ss.str();
        }

    }
}