#ifndef FILL_HPP
#define FILL_HPP

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class Fill : public Command {
        public:
            Fill(int x, int y, int w, int h, Color &fill);
            ~Fill();

            Image *apply(Image *img) override;
            std::string toString() const override;

        private:
            int x, y, w, h;
            Color fill;
        };
    }
}

#endif //FILL_HPP
