#include <ctime>
#include <cstdlib>
#include "check_answer.hpp"

bool check_answer::is_median_point (point p, std::vector<line> &g) {
	int below = 0, above = 0;
	for (line l:g) {
		if (p.is_below(l)) above++;
		if (p.is_above(l)) below++;
	}
	return above <= g.size()/2 && below <= g.size()/2;
}

bool check_answer::check_answer (point p, std::vector<line> &g1, 
std::vector<line> &g2) {
	return is_median_point(p, g1) && is_median_point(p, g2);
}