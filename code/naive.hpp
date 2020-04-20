#include <vector>
#include "line.hpp"
#include "point.hpp"

namespace naive {

	bool bissects (line l, std::vector<point> points) ;

	line solve (std::vector<point> &red, 
			std::vector<point> &blue);

}
