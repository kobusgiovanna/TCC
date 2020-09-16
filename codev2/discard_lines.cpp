#include "discard_lines.hpp"

void discard_lines::discard_lines
(std::vector<line> &g1, int &p1, trapezoid tau) {
	std::vector<line> new_g1;
	for (auto l : g1) {
		if (tau.intersects(l)) new_g1.push_back(l);
		if (tau.above(l)) p1--;
	}
	g1 = new_g1;
	return;
}
