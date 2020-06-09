#ifndef LINE_H 
#define LINE_H

#include "point.hpp"

class point;

class line {

	public:

		double m, b;

		line (double m, double b);

		line (point a, point b);

		bool equals (line l);

		point dual ();

		bool is_on (point p);

		bool is_above (point p);

		bool is_below (point p);

		double eval (double x);

};

#endif