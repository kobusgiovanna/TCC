#include <vector>
#include "point.hpp"
#include "interval.hpp"
#include "phase_1_nlogn.hpp"
#include "phase_2.hpp"
#include "phase_3.hpp"
#include "optimized_naive_dual.hpp"

namespace nlogn_dual {

	point find_cut (std::vector<line> g1, std::vector<line> g2);
	
}
