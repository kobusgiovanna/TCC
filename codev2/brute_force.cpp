#include <ctime>
#include <cstdlib>
#include <iostream>
#include "brute_force.hpp"

bool brute_force::is_pth_level (std::vector<line> g, int p, point i) {
	int below = 0;
	for (line gg : g) {
		if (gg.is_below(i)) below++;
	}
	return below == p;
}
	
point brute_force::brute_force (std::vector<line> g1, std::vector<line> g2, 
int p1, int p2, interval t) {
	for (auto l1 : g1) {
		for (auto l2 : g2) {
			point pre = point(l1, l2);
			if (!t.contains(pre.x)) continue;
			if (is_pth_level(g1, p1, pre) && is_pth_level(g2, p2, pre)) {
				return pre;
			}
		}
	}
	return point(0, 0);
}