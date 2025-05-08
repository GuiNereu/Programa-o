#ifndef ROTATERIGHT_HPP
#define ROTATERIGHT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class RotateRight : public Command {
        public:
            RotateRight();
            ~RotateRight();

            Image *apply(Image *img) override;
            std::string toString() const override;
        };
    }
}

#endif //ROTATERIGHT_HPP
