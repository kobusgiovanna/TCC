
#include <vector>
#include "line.hpp"
#include "point.hpp"

namespace phase_1_nlogn {

	bool smaller_eval (line l, line m, double x);

	std::pair<int,std::pair<int,int>> inversions_and_random_inversion
	(std::vector<int> &v, int i, int j);

	std::pair<int,std::pair<int,int>> inversions_and_random_inversion
	(std::vector<int> v);

	int inversions (std::vector<int> v);

	std::pair<int, int> random_inversion (std::vector<int> v);

	std::pair<int,std::pair<line,line>> intersections_and_random_intersection
	(std::vector<line> v, std::pair<double, double> t);

	int intersections (std::vector<line> v, std::pair<double, double> t);

	std::pair<line,line> random_intersection
	(std::vector<line> v, std::pair<double, double> t);

	line pth_level(std::vector<line> v, int p, double x);

	bool odd_level_intersection (std::vector<line> g1,
	std::vector<line> g2, int p1, int p2, std::pair<double, double> t);
	
	std::pair<double, double> new_interval (std::vector<line> g1,
	std::vector<line> g2, int p1, int p2, std::pair<double, double> t);

}
