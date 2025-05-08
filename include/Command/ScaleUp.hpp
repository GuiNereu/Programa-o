#ifndef SCALEUP_HPP
#define SCALEUP_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class ScaleUp : public Command {
        public:
            ScaleUp(int x_factor, int y_factor);
            ~ScaleUp();

            Image *apply(Image *img) override;
            std::string toString() const override;

        private:
            int x_factor;
            int y_factor;
        };
    }
}

#endif //SCALEUP_HPP
