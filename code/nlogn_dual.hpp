#include <vector>
#include "point.hpp"
#include "interval.hpp"
#include "phase_1_nlogn.hpp"
#include "phase_2.hpp"
#include "phase_3.hpp"
#include "optimized_naive_dual.hpp"

namespace nlogn_dual {

	bool is_pth_level (std::vector<line> g, int p, point i);
	
	point brute (std::vector<line> g1, std::vector<line> g2, 
		int p1, int p2, interval t);

	line pth_slope(std::vector<line> &v, int i, int j, int p);

	line pth_slope(std::vector<line> v, int p);

	interval max_interval
	(std::vector<line> g1, std::vector<line> g2, int p1, int p2);

	point solve (std::vector<line> g1, std::vector<line> g2);
	
}
