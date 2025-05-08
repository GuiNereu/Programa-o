#ifndef RESIZE_HPP
#define RESIZE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Resize : public Command {
        public:
            Resize(int x, int y, int w, int h);
            ~Resize();

            Image *apply(Image *img) override;
            std::string toString() const override;

        private:
            int x;
            int y;
            int w;
            int h;
        };
    }
}

#endif //RESIZE_HPP
