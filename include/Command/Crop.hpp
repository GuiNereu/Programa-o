#ifndef CROP_HPP
#define CROP_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Crop : public Command {
        public:
            Crop(int x, int y, int w, int h);
            ~Crop();

            Image *apply(Image *img) override;
            std::string toString() const override;

        private:
            int x;
            int y;
            int w;
            int h;
        };
    }
}

#endif //CROP_HPP
