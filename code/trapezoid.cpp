#include "trapezoid.hpp"

trapezoid::trapezoid (point left_up, point left_down, point right_up,
		point right_down) : 
	left_up(left_up), left_down(left_down), right_up(right_up),
			right_down(right_down) {}

bool trapezoid::intersects (line l) {
	if (l.is_below(left_down) && l.is_below(right_down)) return 0;
	if (l.is_above(left_up) && l.is_above(right_up)) return 0;
	return 1;
}

bool trapezoid::above (line l) {
	if (l.is_below(left_down) && l.is_below(right_down)) return 1;
	return 0;
}
