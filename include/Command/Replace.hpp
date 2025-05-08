#ifndef REPLACE_HPP
#define REPLACE_HPP

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class Replace : public Command {
        public:
            Replace(Color &from, Color &to);
            ~Replace();

            Image *apply(Image *img) override;
            std::string toString() const override;

        private:
            Color from;
            Color to;
        };
    }
}

#endif //REPLACE_HPP
