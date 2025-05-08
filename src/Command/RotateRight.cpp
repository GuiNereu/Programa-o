#include "Command/RotateRight.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        RotateRight::RotateRight() : Command("RotateRight") {}

        RotateRight::~RotateRight() {}

        Image *RotateRight::apply(Image *img) {
            int old_w = img->width();
            int old_h = img->height();

            // Use top-left pixel as fill color
            Color fill = img->at(0, 0);

            Image *rotated = new Image(old_h, old_w, fill);

            for (int y = 0; y < old_h; ++y) {
                for (int x = 0; x < old_w; ++x) {
                    rotated->at(old_h - 1 - y, x) = img->at(x, y);
                }
            }

            delete img;
            return rotated;
        }

        std::string RotateRight::toString() const {
            return name();
        }

    }
}