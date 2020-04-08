#include <vector>
#include <algorithm>
#include "line.hpp"
#include "point.hpp"

namespace optimized_naive_dual {

	struct coloured_line;

	struct pair_of_lines;

	bool at_minus_infinity (line l, line m);

	bool x_of_intersection (pair_of_lines p, pair_of_lines q);

	line solve (std::vector<point> &red_points, 
			std::vector<point> &blue_points);

}
