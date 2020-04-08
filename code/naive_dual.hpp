#include <vector>
#include "line.hpp"
#include "point.hpp"

namespace naive_dual {

	bool is_solution (point p, std::vector<line> &red, 
			std::vector<line> &blue);

	line solve (std::vector<point> &red_points, 
			std::vector<point> &blue_points);

}
