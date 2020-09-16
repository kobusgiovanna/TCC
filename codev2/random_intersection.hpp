#include <vector>
#include "line.hpp"
#include "point.hpp"
#include "interval.hpp"

namespace random_intersection {

	std::pair<long long, std::pair<int, int>> inversions
	(std::vector<int> &v, int i, int j);

	std::pair<long long, point> intersections
	(std::vector<line> v, interval t);

}
