
#include "naive.hpp"

bool naive::is_solution (line l, std::vector<point> &red, 
		std::vector<point> &blue) {

	int red_below = 0, red_above = 0;
	int blue_below = 0, blue_above = 0;

	for (point p:red) {
		if (p.is_below(l)) red_below++;
		if (p.is_above(l)) red_above++;
	}

	for (point p:blue) {
		if (p.is_below(l)) blue_below++;
		if (p.is_above(l)) blue_above++;
	}

	return red_below <= red.size()/2 && 
		   red_above <= red.size()/2 && 
		   blue_below <= blue.size()/2 && 
		   blue_above <= blue.size()/2;

}

line naive::solve (std::vector<point> &red,
		std::vector<point> &blue) {
	
	for (point r:red) {
		for (point b:blue) {
			line l = line(r, b);
			if (is_solution(l, red, blue)) return l;
		}
	}
}