#include "phase_3.hpp"

void phase_3::discard_lines
(std::vector<line> &g1, std::vector<line> &g2, trapezoid tau){
	std::vector<line> new_g1;
	std::vector<line> new_g2;
	for (auto l : g1) {
		if (!tau.intersects(l)) new_g1.push_back(l);
	}
	for (auto l : g2) {
		if (!tau.intersects(l)) new_g2.push_back(l);
	}
	g1 = new_g1;
	g2 = new_g2;
	return;
}
