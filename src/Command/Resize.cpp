#include "Command/Resize.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Resize::Resize(int x, int y, int w, int h) : Command("Resize"), x(x), y(y), w(w), h(h) {}

        Resize::~Resize() {}

        Image *Resize::apply(Image *img) {
            int img_w = img->width();
            int img_h = img->height();

            // Use top-left pixel as fill color
            Color fill = img->at(0, 0);

            Image *resized = new Image(w, h, fill);

            for (int j = 0; j < h; ++j) {
                for (int i = 0; i < w; ++i) {
                    int src_x = x + i;
                    int src_y = y + j;

                    if (src_x >= 0 && src_x < img_w && src_y >= 0 && src_y < img_h) {
                        resized->at(i, j) = img->at(src_x, src_y);
                    }
                    // else already filled with default fill
                }
            }

            delete img;
            return resized;
        }

        std::string Resize::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x << " y:" << y << " w:" << w << " h:" << h;
            return ss.str();
        }

    }
}
