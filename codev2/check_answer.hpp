#include <vector>
#include "line.hpp"
#include "point.hpp"

namespace check_answer {

	bool is_median_point (point p, std::vector<line> &g);

	bool check_answer (point p, std::vector<line> &g1, std::vector<line> &g2);

}
