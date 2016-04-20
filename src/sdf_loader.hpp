#pragma once

#include <iosfwd>
#include <memory>

//#include "sdf_lexer.hpp"
//#include "sdf_parser.gen.hpp"

namespace sdfparse {

//Forward delcarations
class Lexer;
class Parser;

class Loader {

    public:
        Loader();
        ~Loader();
        void load(std::string filename);
        void load(std::istream& is);

    private:
        friend Parser;
        std::string filename_;
        std::unique_ptr<Lexer> lexer_;
        std::unique_ptr<Parser> parser_;
};

} //sdfparse
