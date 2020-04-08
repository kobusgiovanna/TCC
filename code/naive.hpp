#include <vector>
#include "line.hpp"
#include "point.hpp"

namespace naive {

	bool is_solution (line l, std::vector<point> &red, 
			std::vector<point> &blue);

	line solve (std::vector<point> &red, 
			std::vector<point> &blue);

}
