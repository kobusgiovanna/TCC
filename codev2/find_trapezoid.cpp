#include <algorithm> 
#include "find_trapezoid.hpp"

trapezoid find_trapezoid::find_trapezoid
(std::vector<line> g1, int p1, interval t) {
	int offset = g1.size()/8;
	trapezoid tau = trapezoid(
		pth_level::pth_level(g1, p1 + offset, t.left).at(t.left),
		pth_level::pth_level(g1, p1 - offset, t.left).at(t.left),
		pth_level::pth_level(g1, p1 + offset, t.right).at(t.right),
		pth_level::pth_level(g1, p1 - offset, t.right).at(t.right)
	);
	return tau;
}

