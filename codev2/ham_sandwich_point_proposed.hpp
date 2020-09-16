#include <vector>
#include "point.hpp"
#include "line.hpp"
#include "interval.hpp"
#include "trapezoid.hpp"
#include "aux.hpp"

namespace ham_sandwich_point_proposed {

	point solve (std::vector<line> g1, std::vector<line> g2, int seed);
	
}
