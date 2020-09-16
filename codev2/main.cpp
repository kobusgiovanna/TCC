#include <iostream>
#include <iomanip>

#include "check_answer.hpp"
#include "ham_sandwich_point_nlogn.hpp"
#include "ham_sandwich_point_proposed.hpp"

int main() {

	srand(time(NULL));

	std::cout << std::setprecision(10) << std::fixed;

	int red_points = 2000;
	int blue_points = 2000;

	int max_x = 1000000000;
	int min_x = 1000000000;

	int max_y = 1000000000;
	int min_y = 1000000000;	

	std::vector<point> red;
	std::vector<point> blue;
	std::vector<line> red_dual;
	std::vector<line> blue_dual;

	for (int i = 0; i < red_points; i++) {
		red.push_back(point(rand()%(max_x + min_x) - min_x,
			rand()%(max_y + min_y) - min_y));
		red_dual.push_back(red[i].dual());
	}
	for (int i = 0; i < blue_points; i++) {
		blue.push_back(point(rand()%(max_x + min_x) - min_x,
			rand()%(max_y + min_y) - min_y));
		blue_dual.push_back(blue[i].dual());
	}

	std::cout << red.size() << std::endl;
	for (point &p: red) {
		//std::cout << p.dual().m << " " << p.dual().b << std::endl;
	}
	std::cout << blue.size() << std::endl;
	for (point &p: blue) {
		//std::cout << p.dual().m << " " << p.dual().b << std::endl;
	}

	
	point solution = ham_sandwich_point_proposed::solve(red_dual,blue_dual,rand());

	std::cout << solution.x << " " << solution.y << std::endl;

	if (check_answer::check_answer(solution, red_dual, blue_dual)) {
		std::cout << "Correct answer" << std::endl;
	}
	else {
		std::cout << "Invalid answer" << std::endl;
	}
	
}