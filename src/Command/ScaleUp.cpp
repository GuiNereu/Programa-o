#include "Command/ScaleUp.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        ScaleUp::ScaleUp(int x_factor, int y_factor)
            : Command("ScaleUp"), x_factor(x_factor), y_factor(y_factor) {}

        ScaleUp::~ScaleUp() {}

        Image *ScaleUp::apply(Image *img) {
            int old_w = img->width();
            int old_h = img->height();

            int new_w = old_w * x_factor;
            int new_h = old_h * y_factor;

            Color fill = img->at(0, 0); // default fill for new image (if needed)

            Image *scaled = new Image(new_w, new_h, fill);

            for (int y = 0; y < old_h; ++y) {
                for (int x = 0; x < old_w; ++x) {
                    const Color &pixel = img->at(x, y);
                    for (int dy = 0; dy < y_factor; ++dy) {
                        for (int dx = 0; dx < x_factor; ++dx) {
                            scaled->at(x * x_factor + dx, y * y_factor + dy) = pixel;
                        }
                    }
                }
            }

            delete img;
            return scaled;
        }

        std::string ScaleUp::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x_factor << " y:" << y_factor;
            return ss.str();
        }

    }
}