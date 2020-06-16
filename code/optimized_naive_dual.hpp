#include <vector>
#include <algorithm>
#include "line.hpp"
#include "point.hpp"

namespace optimized_naive_dual {

	struct coloured_line;

	struct pair_of_lines;

	bool at_minus_infinity (line l, line m);

	bool x_of_intersection (pair_of_lines p, pair_of_lines q);

	point solve (std::vector<line> red, std::vector<line> blue, int p1,
		int p2);

	point solve (std::vector<line> red, std::vector<line> blue);

}
