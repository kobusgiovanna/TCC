#include <limits>
#include "ham_sandwich_point_nlogn.hpp"
#include "new_interval_nlogn.hpp"
#include "find_trapezoid.hpp"
#include "discard_lines.hpp"
#include "brute_force.hpp"
#include "aux.hpp"

point ham_sandwich_point_nlogn::solve 
(std::vector<line> g1, std::vector<line> g2) {
	if (g1.size()%2 == 0) g1.pop_back(); 	
	if (g2.size()%2 == 0) g2.pop_back(); 
	int p1 = g1.size()/2;
	int p2 = g2.size()/2;
	interval t = interval(std::numeric_limits<double>::lowest(),
		std::numeric_limits<double>::max());
	interval t2 = new_interval_nlogn::new_interval(g1, g2, p1, p2, t);
	while (aux::choose_two(g1.size()) > 32 
			&& aux::choose_two(g2.size()) > 32){
		if (g1.size() > g2.size()) {
			std::swap(g1, g2);
			std::swap(p1, p2);
		}
		t = t2;
		trapezoid tau = find_trapezoid::find_trapezoid(g1, p1, t);
		discard_lines::discard_lines(g1, p1, tau);
		t2 = new_interval_nlogn::new_interval(g1, g2, p1, p2, t);
	}
	return brute_force::brute_force(g1, g2, p1, p2, t);
}
