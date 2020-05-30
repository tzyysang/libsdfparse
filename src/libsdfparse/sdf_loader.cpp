#include <fstream>
#include "sdf_loader.hpp"

#include "sdf_lexer.hpp"
#include "sdf_parser.gen.hpp"
#include "location.hh"

namespace sdfparse {

Loader::Loader()
    : filename_("") //Initialize the filename
    , lexer_(new Lexer())
    , parser_(new Parser(*lexer_, *this)) {
}


//We need to declare the destructor in the .cpp file,
//since to destruct the unique_ptr's we also need the
//full definitions of Lexer and Parser
Loader::~Loader()
    {}

bool Loader::load(std::string filename) {
    std::ifstream is(filename);
    return load(is, filename);
}

bool Loader::load(std::istream& is, std::string filename) {
    assert(is.good());

	std::cout << "SDFLoader: loading " << filename << std::endl;

    //Update the filename for location references
    filename_ = filename;

    //Point the lexer at the new input
    lexer_->switch_streams(&is);

    //Initialize locations with filename
    auto pos = position(&filename_);
    auto loc = location(pos, pos);
    lexer_->set_loc(loc);

    int retval;
    try {
        //Do the parsing
        retval = parser_->parse();

    } catch (ParseError& error) {
        //Users can re-define on_error if they want
        //to do something else (like re-throw)
        on_error(error);
        return false;
    }

    //Bision returns 0 if successful
    return (retval == 0);
}

void Loader::on_error(ParseError& error) {
    //Default implementation, just print out the error
    std::cout << "SDF Error " << error.loc() << ": " << error.what() << "\n";
}

} //sdfparse
