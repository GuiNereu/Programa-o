#ifndef ROTATELEFT_HPP
#define ROTATELEFT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class RotateLeft : public Command {
        public:
            RotateLeft();
            ~RotateLeft();

            Image *apply(Image *img) override;
            std::string toString() const override;
        };
    }
}

#endif //ROTATELEFT_HPP
