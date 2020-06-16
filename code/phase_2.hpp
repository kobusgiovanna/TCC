#include <vector>
#include "line.hpp"
#include "point.hpp"
#include "interval.hpp"
#include "trapezoid.hpp"

namespace phase_2 {

	line pth_level(std::vector<line> &v, int i, int j, int p, double x);

	/*
	levels are indexed from 0
	*/
	line pth_level(std::vector<line> v, int p, double x);

	trapezoid new_trapezoid (std::vector<line> g1,
	std::vector<line> g2, int p1, int p2, interval t);

}
