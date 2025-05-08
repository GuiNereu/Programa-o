#ifndef VMIRROR_HPP
#define VMIRROR_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Vmirror : public Command {
        public:
            Vmirror();
            ~Vmirror();

            Image *apply(Image *img) override;
            std::string toString() const override;
        };
    }
}

#endif //VMIRROR_HPP
