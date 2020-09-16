#include "point.hpp"

#define POINT_EPS 1e-9

point::point (double a, double b) : x(a), y(b) {}

point::point (line l, line m) {
	x = (m.b - l.b)/(l.m - m.m);
	y = l.m*x + l.b;
}

line point::dual () {
	return line (x, -y);
}

bool point::is_on (line l) {
	return fabs(y - (l.m*x + l.b)) <= POINT_EPS;
}

bool point::is_above (line l) {
	return y - (l.m*x + l.b) > POINT_EPS;
}

bool point::is_below (line l) {
	return y - (l.m*x + l.b) < -POINT_EPS;
}