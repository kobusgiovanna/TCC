#include "new_interval_nlogn.hpp"
#include "aux.hpp"
#include "random_intersection.hpp"
#include "odd_level_intersection.hpp"

#define EPS 1e-9

interval new_interval_nlogn::new_interval 
(std::vector<line> g1, std::vector<line> g2, int p1, int p2, interval t) {
	auto aux = random_intersection::intersections(g1, t);
	int n = aux.first;
	point p = aux.second;
	while (aux::choose_two(g1.size()) < 32*n) {
		double pivot = p.x;
		interval t1 = interval(t.left, pivot);
		interval t2 = interval(pivot, t.right);
		if (odd_level_intersection::odd_level_intersection(g1, g2, p1, p2, t1)) {
			t = t1;
		}
		else t = t2;
		aux = random_intersection::intersections(g1, t);
		n = aux.first;
		if (n == 0) break;
		p = aux.second;
	}
	return t;
}