
#include "naive_dual.hpp"

bool naive_dual::is_median_level(point p, std::vector<line> &lines) {
	int below = 0, above = 0;
	for (line l: lines) {
		if (l.is_below(p)) below++;
		if (l.is_above(p)) above++;
	}
	return below <= (int)lines.size()/2 && above <= (int)lines.size()/2;
}

point naive_dual::solve (std::vector<line> red, std::vector<line> blue) {
	for (line r:red) {
		for (line b:blue) {
			point p = point(r, b);
			if (is_median_level(p, blue) && is_median_level(p, red)) {
				return p;
			} 
		}
	}
	return point(0, 0);
}

