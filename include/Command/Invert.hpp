#ifndef INVERT_HPP
#define INVERT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class InvertCommand : public Command {
        public:
            InvertCommand();
            ~InvertCommand();

            Image *apply(Image *img) override;
            std::string toString() const override;
        };
    }
}
#endif //INVERT_HPP
