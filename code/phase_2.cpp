#include <algorithm> 
#include <ctime>
#include "phase_2.hpp"

line phase_2::pth_level(std::vector<line> &v, int i, int j, int p, double x) {
	int r = i + rand()%(j - i + 1);
	int id = i; 
	std::swap(v[r], v[j]);
	for (int k = i; k < j; k++) {
		if (v[k].smaller_eval(v[j], x)) {
			std::swap(v[k], v[id]);
			id++;
		}
	}
	std::swap(v[j], v[id]);
	if (id - i > p) return pth_level(v, i, id - 1, p, x);
	if (id - i < p) return pth_level(v, id + 1, j, p - (id - i + 1), x);
	return v[id];
}

line phase_2::pth_level(std::vector<line> v, int p, double x) {
	p = std::min(p, (int)v.size() - 1);
	p = std::max(p, 0);
	std::random_shuffle(v.begin(), v.end());
	return pth_level(v, 0, (int)v.size() - 1, p, x);
}

trapezoid phase_2::new_trapezoid
(std::vector<line> g1, std::vector<line> g2, int p1, int p2, interval t) {
	if (g2.size() > g1.size()){
		std::swap(g1, g2);
		std::swap(p1, p2);
	}
	int offset = g1.size()/8;
	trapezoid tau = trapezoid(
		pth_level(g1, p1 + offset, t.left).at(t.left),
		pth_level(g1, p1 - offset, t.left).at(t.left),
		pth_level(g1, p1 + offset, t.right).at(t.right),
		pth_level(g1, p1 - offset, t.right).at(t.right));
	return tau;
}

