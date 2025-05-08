#ifndef MOVE_HPP
#define MOVE_HPP

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class Move : public Command {
        public:
            Move(int dx, int dy);
            ~Move();

            Image *apply(Image *img) override;
            std::string toString() const override;

        private:
            int dx;
            int dy;
        };
    }
}

#endif //MOVE_HPP
