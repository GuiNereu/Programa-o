#include "Command/ToGrayScale.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        ToGrayScale::ToGrayScale() : Command("ToGrayScale") {}

        ToGrayScale::~ToGrayScale() {}

        Image *ToGrayScale::apply(Image *img) {
            if (!img) return nullptr;

            int w = img->width();
            int h = img->height();

            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w; ++x) {
                    Color &pixel = img->at(x, y);
                    int v = (pixel.red() + pixel.green() + pixel.blue()) / 3;
                    pixel.red() = pixel.green() = pixel.blue() = static_cast<rgb_value>(v);
                }
            }

            return img;
        }

        std::string ToGrayScale::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}