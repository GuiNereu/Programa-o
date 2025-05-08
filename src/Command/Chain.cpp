#include "Command/Chain.hpp"
#include "ScrimParser.hpp"
#include "Logger.hpp"
#include <fstream>
#include <sstream>

namespace prog {
    namespace command {

        Chain::Chain(const std::vector<std::string>& files, std::set<std::string> seen)
                : Command("Chain"), files(files), seen(seen) {}

        Chain::~Chain() {}

        Image* Chain::apply(Image* img) {
            for (const std::string& filename : files) {
                if (seen.count(filename)) {
                    *Logger::err() << "Skipping recursive chain file: " << filename << "\n";
                    continue;
                }

                seen.insert(filename);
                ScrimParser parser;
                std::vector<Command*> cmds = parser.parse(filename, seen);
                std::vector<Command*> filtered;

                for (Command* cmd : cmds) {
                    std::string n = cmd->name();
                    if (n == "save" || n == "blank" || n == "open") {
                        delete cmd;
                    } else {
                        filtered.push_back(cmd);
                    }
                }

                Scrim sub_scrim(filtered);
                img = sub_scrim.run(img);
            }

            return img;
        }

        std::string Chain::toString() const {
            std::ostringstream ss;
            ss << name() << " [";
            for (const std::string& f : files) {
                ss << f << " ";
            }
            ss << "]";
            return ss.str();
        }

    }
}