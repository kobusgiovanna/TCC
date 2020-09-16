#include "interval.hpp"

const double INTERVAL_EPS = 1e-9;

interval::interval (double left, double right) :
	left(left), right(right) {}

bool interval::contains (double x) {
	if (x + INTERVAL_EPS > left && x + INTERVAL_EPS < right) {
		return 1;
	} 
	return 0;
}