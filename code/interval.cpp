#include "interval.hpp"

const double INTERVAL_EPS = 1e-9;

interval::interval (double left, double right) :
	left(left), right(right) {}

bool interval::contains (double x) {
	if (x > left + INTERVAL_EPS && x < right + INTERVAL_EPS) {
		return 1;
	} 
	return 0;
}