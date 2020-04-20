
#include "naive.hpp"

bool naive::bissects (line l, std::vector<point> points) {
	int below = 0, above = 0;
	for (point p:points) {
		if (p.is_below(l)) below++;
		if (p.is_above(l)) above++;
	}
	return below <= (int)points.size()/2 && above <= (int)points.size()/2;
}

line naive::solve (std::vector<point> &red,
		std::vector<point> &blue) {
	
	for (point r:red) {
		for (point b:blue) {
			line l = line(r, b);
			if (bissects(l, red) && bissects(l, blue)){
				return l;
			} 
		}
	}

	return line(0, 0);
}