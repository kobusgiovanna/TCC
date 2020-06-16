#include "nlogn_dual.hpp"

point nlogn_dual::find_cut (std::vector<line> g1, std::vector<line> g2) {
	if (g1.size()%2 == 0) g1.pop_back(); 	
	if (g2.size()%2 == 0) g2.pop_back(); 
	int p1 = g1.size()/2;
	int p2 = g2.size()/2;
	interval t = interval(DOUBLE_MIN, DOUBLE_MAX);
	auto next_interval = phase_1_nlogn::new_interval(g1, g2, p1, p2, t);
	while (next_interval.second == 0){
		trapezoid tau = 
				phase_2::new_trapezoid(g1, g2, p1, p2, next_interval.first);
		phase_3::discard_lines(g1, g2, tau);
		auto next_interval = phase_1_nlogn::new_interval(g1, g2, p1, p2, t);
	}
	//ai eu bruto, nao eh isso mas eh quase isso
	return optimized_naive_dual::solve(g1, g2);
}
