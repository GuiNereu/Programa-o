#include "Command/Slide.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Slide::Slide(int dx, int dy) : Command("Slide"), dx(dx), dy(dy) {}

        Slide::~Slide() {}

        Image *Slide::apply(Image *img) {
            int w = img->width();
            int h = img->height();
            Image *result = new Image(w, h);

            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w; ++x) {
                    int new_x = (x + dx) % w;
                    int new_y = (y + dy) % h;
                    result->at(new_x, new_y) = img->at(x, y);
                }
            }

            delete img;
            return result;
        }

        std::string Slide::toString() const {
            std::ostringstream ss;
            ss << name() << " dx:" << dx << " dy:" << dy;
            return ss.str();
        }

    }
}