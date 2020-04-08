#include <vector>
#include <algorithm>
#include "line.hpp"
#include "point.hpp"

namespace optimized_naive {

	struct coloured_point;

	struct pair_of_points;

	bool x_coordinate (point l, point m);

	bool slope_of_connecting_line (pair_of_points p, pair_of_points q);

	line solve (std::vector<point> red, 
			std::vector<point> blue);

}
