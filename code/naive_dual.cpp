
#include "naive_dual.hpp"

bool naive_dual::is_solution (point p, std::vector<line> &red, 
		std::vector<line> &blue) {

	int red_below = 0, red_above = 0;
	int blue_below = 0, blue_above = 0;

	for (line l:red) {
		if (l.is_below(p)) red_below++;
		if (l.is_above(p)) red_above++;
	}

	for (line l:blue) {
		if (l.is_below(p)) blue_below++;
		if (l.is_above(p)) blue_above++;
	}

	return red_below <= red.size()/2 && 
		   red_above <= red.size()/2 && 
		   blue_below <= blue.size()/2 && 
		   blue_above <= blue.size()/2;

}

line naive_dual::solve (std::vector<point> &red_points,
		std::vector<point> &blue_points) {

	std::vector<line> red;
	std::vector<line> blue;

	for (point p:red_points) red.push_back(p.dual());
	for (point p:blue_points) blue.push_back(p.dual());

	for (line r:red) {
		for (line b:blue) {
			point p = point(r, b);
			if (is_solution(p, red, blue)) return p.dual();
		}
	}
}

