#include <vector>
#include "line.hpp"
#include "point.hpp"
#include "interval.hpp"

namespace phase_1_nlogn {

	std::pair<long long, std::pair<int, int>> inversions
	(std::vector<int> &v, int i, int j);

	/*
	returns the number of inversions and a random inversion of a given
	permutation
	*/
	std::pair<long long, std::pair<int, int>> inversions
	(std::vector<int> v);

	/*
	returns the number of intersections in a certain interval given a
	set of lines
	*/
	std::pair<long long, std::pair<line, line>> intersections
	(std::vector<line> v, interval t);

	line pth_level(std::vector<line> v, int p, double x);

	bool odd_level_intersection (std::vector<line> g1,
	std::vector<line> g2, int p1, int p2, interval t);


	long long max_intersections
	(std::vector<line> g1);

	/*
	levels are indexed from 0
	returns the {new_interval, 0} if the new interval is not the base case
	and {new_interval, 1} otherwise
	*/
	std::pair<interval, bool> new_interval (std::vector<line> g1,
	std::vector<line> g2, int p1, int p2, interval t);

}
