#include <vector>
#include "line.hpp"
#include "point.hpp"

namespace naive_dual {

	bool is_median_level(point p, std::vector<line> &lines);

	line solve (std::vector<point> &red_points, 
			std::vector<point> &blue_points);

}
