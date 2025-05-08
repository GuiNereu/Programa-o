#include "Command/RotateLeft.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        RotateLeft::RotateLeft() : Command("RotateLeft") {}

        RotateLeft::~RotateLeft() {}

        Image *RotateLeft::apply(Image *img) {
            int old_w = img->width();
            int old_h = img->height();

            // Use top-left pixel as fill color
            Color fill = img->at(0, 0);

            Image *rotated = new Image(old_h, old_w, fill);

            for (int y = 0; y < old_h; ++y) {
                for (int x = 0; x < old_w; ++x) {
                    rotated->at(y, old_w - 1 - x) = img->at(x, y);
                }
            }

            delete img;
            return rotated;
        }

        std::string RotateLeft::toString() const {
            return name();
        }

    }
}