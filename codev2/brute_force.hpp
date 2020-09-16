#include <vector>
#include "line.hpp"
#include "point.hpp"
#include "interval.hpp"

namespace brute_force {

	bool is_pth_level (std::vector<line> g, int p, point i);
	
	point brute_force (std::vector<line> g1, std::vector<line> g2, 
		int p1, int p2, interval t);

}
