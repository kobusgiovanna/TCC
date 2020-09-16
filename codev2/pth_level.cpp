#include <algorithm>
#include <ctime>
#include "pth_level.hpp"

line pth_level::pth_level
(std::vector<line> &v, int i, int j, int p, double x) {
	srand(time(NULL));
	int r = i + rand()%(j - i + 1);
	int id = i; 
	std::swap(v[r], v[j]);
	for (int k = i; k < j; k++) {
		if (v[k].smaller_eval(v[j], x)) std::swap(v[k], v[id++]);
	}
	std::swap(v[j], v[id]);
	if (id - i > p) {
		return pth_level(v, i, id - 1, p, x);
	}
	if (id - i < p) {
		return pth_level(v, id + 1, j, p - (id - i + 1), x);
	}
	return v[id];
}

line pth_level::pth_level(std::vector<line> v, int p, double x) {
	p = std::min(p, (int)v.size() - 1);
	p = std::max(p, 0);
	return pth_level(v, 0, (int)v.size() - 1, p, x);
}