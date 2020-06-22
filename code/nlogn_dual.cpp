#include "nlogn_dual.hpp"
#include <cfloat>

point nlogn_dual::brute (std::vector<line> g1, std::vector<line> g2, 
		int p1, int p2, interval t){
	for (auto l1 : g1) {
		for (auto l2 : g2) {
			point pre = point(l1, l2);
			if (!t.contains(pre.x)) continue;
			int below1 = 0, below2 = 0;
			for (auto ll1 : g1) {
				if (ll1.is_below(pre)) below1++;
			}
			for (auto ll2 : g2) {
				if (ll2.is_below(pre)) below2++;
			}
			if (below1 == p1 && below2 == p2) return pre;
		}
	}
	return point(0, 0);
}

line nlogn_dual::pth_slope(std::vector<line> &v, int i, int j, int p) {
	int r = (i + rand()%(j - i + 1));
	int id = i; 
	std::swap(v[r], v[j]);
	for (int k = i; k < j; k++) {
		if (v[k].m < v[j].m) {
			std::swap(v[k], v[id]);
			id++;
		}
	}
	std::swap(v[j], v[id]);
	if (id - i > p) return pth_slope(v, i, id - 1, p);
	if (id - i < p) return pth_slope(v, id + 1, j, p - (id - i + 1));
	return v[id];
}

line nlogn_dual::pth_slope(std::vector<line> v, int p) {
	p = std::min(p, (int)v.size() - 1);
	p = std::max(p, 0);
	return pth_slope(v, 0, (int)v.size() - 1, p);
}

interval nlogn_dual::max_interval
(std::vector<line> g1, std::vector<line> g2, int p1, int p2){
	interval t = interval(0, 0);
	line l1 = pth_slope(g1, p1);
	line l2 = pth_slope(g2, p2);
	for (auto l : g2) {
		t.left = std::min(t.left, point(l1, l).x - 1);
		t.right = std::max(t.right, point(l1, l).x + 1);
	}
	for (auto l : g1) {
		t.left = std::min(t.left, point(l2, l).x - 1);
		t.right = std::max(t.right, point(l2, l).x + 1);
	}
	return t;
}

point nlogn_dual::solve (std::vector<line> g1, std::vector<line> g2) {
	if (g1.size()%2 == 0) g1.pop_back(); 	
	if (g2.size()%2 == 0) g2.pop_back(); 
	int p1 = g1.size()/2;
	int p2 = g2.size()/2;
	interval t = max_interval(g1, g2, p1, p2);
	auto next_interval = phase_1_nlogn::new_interval(g1, g2, p1, p2, t);
	while (next_interval.second == 0){
		t = next_interval.first;
		trapezoid tau = phase_2::new_trapezoid(g1, g2, p1, p2, t);
		phase_3::discard_lines(g1, g2, p1, p2, tau);
		next_interval = phase_1_nlogn::new_interval(g1, g2, p1, p2, t);
	}
	return brute(g1, g2, p1, p2, t);
}
