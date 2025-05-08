#ifndef ADD_HPP
#define ADD_HPP

#include "Command.hpp"
#include "Color.hpp"
#include <string>

namespace prog {
    namespace command {
        class Add : public Command {
        public:
            Add(const std::string &filename, const Color &neutral, int x, int y);
            ~Add();

            Image *apply(Image *img) override;
            std::string toString() const override;

        private:
            std::string filename;
            Color neutral;
            int x;
            int y;
        };
    }
}

#endif //ADD_HPP
