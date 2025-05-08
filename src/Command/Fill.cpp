#include "Command/Fill.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Fill::Fill(int x, int y, int w, int h, Color &fill)
            : Command("Fill"), x(x), y(y), w(w), h(h), fill(fill) {}

        Fill::~Fill() {}

        Image *Fill::apply(Image *img) {
            int img_w = img->width();
            int img_h = img->height();

            for (int dy = 0; dy < h; ++dy) {
                for (int dx = 0; dx < w; ++dx) {
                    int px = x + dx;
                    int py = y + dy;

                    if (px >= 0 && px < img_w && py >= 0 && py < img_h) {
                        img->at(px, py) = fill;
                    }
                }
            }

            return img;
        }

        std::string Fill::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x << " y:" << y
               << " w:" << w << " h:" << h << " fill:" << fill;
            return ss.str();
        }

    }
}