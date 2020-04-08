#ifndef POINT_H 
#define POINT_H

#include <cmath>
#include "line.hpp"

class line;

class point {

	public:

		double x, y;

		point (double a, double b);

		point (line a, line b);

		line dual ();

		bool is_on (line l);

		bool is_above (line l);

		bool is_below (line l);

};

#endif