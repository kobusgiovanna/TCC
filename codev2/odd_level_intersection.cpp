#include <ctime>
#include <cstdlib>
#include "odd_level_intersection.hpp"
#include "pth_level.hpp"

bool odd_level_intersection::odd_level_intersection (std::vector<line> g1,
		std::vector<line> g2, int p1, int p2, interval t) {
	line l1 = pth_level::pth_level(g1, p1, t.left);
	line l2 = pth_level::pth_level(g2, p2, t.left);
	bool order_left = l1.smaller_eval(l2, t.left);
	l1 = pth_level::pth_level(g1, p1, t.right);
	l2 = pth_level::pth_level(g2, p2, t.right);
	bool order_right = l1.smaller_eval(l2, t.right);
	return order_left != order_right;
}