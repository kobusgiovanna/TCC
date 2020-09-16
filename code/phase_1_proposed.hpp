#include <vector>
#include "line.hpp"
#include "point.hpp"
#include "interval.hpp"

namespace phase_1_proposed {

	point random_intersection
	(std::vector<line> &g1);

	interval new_interval (std::vector<line> g1,
	std::vector<line> g2, int p1, int p2, interval t);

}
