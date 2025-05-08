#ifndef CHAIN_HPP
#define CHAIN_HPP

#include "Command.hpp"
#include <set>
#include <vector>
#include <string>

namespace prog {
    namespace command {
        class Chain : public Command {
        public:
            Chain(const std::vector<std::string>& files, std::set<std::string> seen = {});
            ~Chain();

            Image* apply(Image* img) override;
            std::string toString() const override;

        private:
            std::vector<std::string> files;
            std::set<std::string> seen;
        };
    }
}

#endif //CHAIN_HPP
