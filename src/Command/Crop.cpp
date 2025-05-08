#include "Command/Crop.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Crop::Crop(int x, int y, int w, int h) : Command("Crop"), x(x), y(y), w(w), h(h) {}

        Crop::~Crop() {}

        Image *Crop::apply(Image *img) {
            int img_w = img->width();
            int img_h = img->height();

            Image *cropped = new Image(w, h);

            for (int j = 0; j < h; ++j) {
                for (int i = 0; i < w; ++i) {
                    int src_x = x + i;
                    int src_y = y + j;

                    if (src_x >= 0 && src_x < img_w && src_y >= 0 && src_y < img_h) {
                        cropped->at(i, j) = img->at(src_x, src_y);
                    }
                }
            }

            delete img;
            return cropped;
        }

        std::string Crop::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x << " y:" << y << " w:" << w << " h:" << h;
            return ss.str();
        }

    }
}