#include <vector>
#include "line.hpp"
#include "point.hpp"

namespace naive_dual {

	bool is_median_level(point p, std::vector<line> &lines);

	point solve (std::vector<line> red, std::vector<line> blue);

}
