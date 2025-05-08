#ifndef HMIRROR_HPP
#define HMIRROR_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Hmirror : public Command {
        public:
            Hmirror();
            ~Hmirror();

            Image *apply(Image *img) override;
            std::string toString() const override;
        };
    }
}

#endif //HMIRROR_HPP
