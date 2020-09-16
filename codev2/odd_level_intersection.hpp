#include <vector>
#include "line.hpp"
#include "point.hpp"
#include "interval.hpp"

namespace odd_level_intersection {

	bool odd_level_intersection (std::vector<line> g1,
		std::vector<line> g2, int p1, int p2, interval t);

}
