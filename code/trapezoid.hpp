#ifndef TRAPEZOID_H 
#define TRAPEZOID_H

#include "point.hpp"
#include "line.hpp"

class trapezoid {

	public:

		point left_up, left_down;
		point right_up, right_down;

		trapezoid (point left_up, point left_down, point right_up,
				point right_down);

		bool intersects (line l);


};

#endif