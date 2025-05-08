#include "Command/Move.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Move::Move(int dx, int dy) : Command("Move"), dx(dx), dy(dy) {}

        Move::~Move() {}

        Image *Move::apply(Image *img) {
            int w = img->width();
            int h = img->height();
            Image *result = new Image(w, h, Color(255, 255, 255));  // White fill

            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w; ++x) {
                    int new_x = x + dx;
                    int new_y = y + dy;
                    if (new_x < w && new_y < h) {
                        result->at(new_x, new_y) = img->at(x, y);
                    }
                }
            }

            delete img;
            return result;
        }

        std::string Move::toString() const {
            std::ostringstream ss;
            ss << name() << " dx:" << dx << " dy:" << dy;
            return ss.str();
        }

    }
}