#include "Command/Invert.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        InvertCommand::InvertCommand() : Command("Invert") {}

        InvertCommand::~InvertCommand() {}

        Image *InvertCommand::apply(Image *img) {
            if (!img) return nullptr;

            int w = img->width();
            int h = img->height();

            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w; ++x) {
                    Color &pixel = img->at(x, y);
                    pixel.red() = 255 - pixel.red();
                    pixel.green() = 255 - pixel.green();
                    pixel.blue() = 255 - pixel.blue();
                }
            }

            return img;
        }

        std::string InvertCommand::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}