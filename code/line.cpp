#include "line.hpp"

#define LINE_EPS 1e-9

line::line (double m, double b) : m(m), b(b) {}

line::line (point p, point q) {
	m = (q.y - p.y)/(q.x - p.x);
	b = p.y - m*p.x; 
}

bool line::equals (line l) {
	return fabs(m-l.m) < LINE_EPS && fabs(b-l.b) < LINE_EPS;
}

point line::dual () {
	return point (m, -b);
}

bool line::is_on (point p) {
	return fabs(p.y - (m*p.x + b)) <= LINE_EPS;
}

bool line::is_above (point p) {
	return p.y - (m*p.x + b) < -LINE_EPS;
}

bool line::is_below (point p) {
	return p.y - (m*p.x + b) > LINE_EPS;
}

double line::eval (double x) {
	return m*x + b;
}

point line::at (int x) {
	return point(x, eval(x));
}

bool line::smaller_eval (line m, double x) {
	if (fabs(eval(x) - m.eval(x)) > LINE_EPS) {
		return eval(x) < m.eval(x);
	}
	return this->m > m.m;
}