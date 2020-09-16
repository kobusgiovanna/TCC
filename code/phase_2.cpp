#include <algorithm> 
#include "phase_2.hpp"

line phase_2::pth_level(std::vector<line> &v, int i, int j, int p, double x) {
	int r = i + rand()%(j - i + 1);
	int id = i; 
	std::swap(v[r], v[j]);
	for (int k = i; k < j; k++) {
		if (v[k].smaller_eval(v[j], x)) {
			std::swap(v[k], v[id++]);
		}
	}
	std::swap(v[j], v[id]);
	if (id - i > p) {
		return pth_level(v, i, id - 1, p, x);
	}
	if (id - i < p){
		return pth_level(v, id + 1, j, p - (id - i + 1), x);
	}
	return v[id];
}

line phase_2::pth_level(std::vector<line> v, int p, double x) {
	p = std::min(p, (int)v.size() - 1);
	p = std::max(p, 0);
	return pth_level(v, 0, (int)v.size() - 1, p, x);
}

trapezoid phase_2::new_trapezoid
(std::vector<line> g1, int p1, interval t) {
	int offset = g1.size()/8;
	trapezoid tau = trapezoid(
		pth_level(g1, p1 + offset, t.left).at(t.left),
		pth_level(g1, p1 - offset, t.left).at(t.left),
		pth_level(g1, p1 + offset, t.right).at(t.right),
		pth_level(g1, p1 - offset, t.right).at(t.right)
	);
	return tau;
}

