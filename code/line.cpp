#include "line.hpp"

#define LINE_EPS 1e-9

line::line (double x, double y) : m(x), b(y) {}

line::line (point p, point q) {
	m = (q.y - p.y)/(q.x - p.x);
	b = p.y - m*p.x; 
}

bool line::equals (line l) {
	return abs(m-l.m) < LINE_EPS && abs(b-l.b) < LINE_EPS;
}

point line::dual () {
	return point (m, -b);
}

bool line::is_on (point p) {
	return abs(p.y - (m*p.x + b)) <= LINE_EPS;
}

bool line::is_above (point p) {
	return p.y - (m*p.x + b) < -LINE_EPS;
}

bool line::is_below (point p) {
	return p.y - (m*p.x + b) > LINE_EPS;
}