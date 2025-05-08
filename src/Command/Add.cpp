#include "Command/Add.hpp"
#include "Command/Open.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include "Logger.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Add::Add(const std::string &filename, const Color &neutral, int x, int y)
            : Command("Add"), filename(filename), neutral(neutral), x(x), y(y) {}

        Add::~Add() {}

        Image *Add::apply(Image *img) {
            Open loader(filename);
            Image *overlay = loader.apply(nullptr);

            if (!overlay) {
                *Logger::err() << "Failed to load image: " << filename << "\n";
                return img;
            }

            int overlay_w = overlay->width();
            int overlay_h = overlay->height();
            int base_w = img->width();
            int base_h = img->height();

            for (int i = 0; i < overlay_w; ++i) {
                for (int j = 0; j < overlay_h; ++j) {
                    Color &pixel = overlay->at(i, j);
                    if (pixel.red() != neutral.red() ||
                        pixel.green() != neutral.green() ||
                        pixel.blue() != neutral.blue()) {

                        int target_x = x + i;
                        int target_y = y + j;

                        if (target_x >= 0 && target_x < base_w &&
                            target_y >= 0 && target_y < base_h) {
                            img->at(target_x, target_y) = pixel;
                            }
                        }
                }
            }

            delete overlay;
            return img;
        }

        std::string Add::toString() const {
            std::ostringstream ss;
            ss << name() << " file:" << filename
               << " neutral:" << neutral
               << " x:" << x << " y:" << y;
            return ss.str();
        }

    }
}
