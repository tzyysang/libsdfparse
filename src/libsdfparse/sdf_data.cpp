#include "sdf_data.hpp"
#include "sdf_escape.hpp"
#include <iostream>
#include <cmath>

namespace /*anonymous*/ {
    std::string ident(int depth);

    std::string ident(int depth) {
        return std::string(2*depth, ' ');
    }
}
namespace sdfparse {

	void DelayFile::report_information(std::ostream& os) {
		
		int num_cell = 0;
		for( Cell* cell : cells() ){
			++num_cell;
		}
			
		os << "======== SDF information ========" << std::endl;
		os << "No. of cell:      " << num_cell << std::endl;
		os << "=================================" << std::endl;
	}

} //sdfparse
