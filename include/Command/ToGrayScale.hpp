#ifndef TOGRAYSCALE_HPP
#define TOGRAYSCALE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class ToGrayScale : public Command {
        public:
            ToGrayScale();
            ~ToGrayScale();

            Image *apply(Image *img) override;
            std::string toString() const override;
        };
    }
}

#endif //TOGRAYSCALE_HPP
