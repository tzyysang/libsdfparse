#include <iostream>

#include "sdfparse.hpp"

int main(int argc, char** argv) {

    if(argc != 2) {
        std::cout << "Usage: " << argv[0] << " sdf_file" << "\n";
        return 1;
    }

    sdfparse::Loader sdf_loader;
    bool loaded = sdf_loader.load(argv[1]);
    if(loaded) {
        std::cout << "Successfully loaded SDF\n";

        auto delayfile = sdf_loader.get_delayfile();
        //delayfile.print(std::cout);
        return 0;
    } else {
        std::cout << "Failed to load SDF\n";
        return 1;
    }
}
