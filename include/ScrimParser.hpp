#ifndef PROJECT_SCRIPTPARSER_H
#define PROJECT_SCRIPTPARSER_H

#include "Scrim.hpp"
#include <iostream>
#include <set>

namespace prog {
    class ScrimParser {
    public:
        ScrimParser();
        ~ScrimParser();


        /**
         * Base method that parses an input script, from a generic input stream.
         *
         * @param input
         * @return a **new** ImagePipeline built from the script defined in the input stream
         */
        Scrim* parseScrim(std::istream& input);

        /**
         * Helper method that accepts a file.
         *
         * @param filename
         * @return a **new** ImagePipeline built from the script defined in the given file
         */
        Scrim* parseScrim(const std::string& filename);
        std::vector<Command*> parse(const std::string& filename, std::set<std::string>& seen);

    private: /** Para suportar o chain command **/
        Command* parse_command(std::string command_name, std::istream& input);
    };
}

#endif //PROJECT_SCRIPTPARSER_H
