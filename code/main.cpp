#include <iostream>
#include <iomanip>

#include "naive.hpp"
#include "naive_dual.hpp"
#include "optimized_naive.hpp"
#include "optimized_naive_dual.hpp"
#include "nlogn_dual.hpp"

bool is_solution (line l, std::vector<point> &red, 
		std::vector<point> &blue) {

	return naive::bissects(l, red) && naive::bissects(l, blue);

}

int main() {

	srand(time(NULL));

	std::cout << std::setprecision(10) << std::fixed;

	std::string algorithm = "nlogn_dual";

	//std::cin >> algorithm;

	int red_points = 9;
	int blue_points = 9;

	int max_x = 100;
	int min_x = 100;

	int max_y = 100;
	int min_y = 100;	

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
	for (point p: red) {
		std::cout << p.x << " " << p.y << std::endl;
	}
	std::cout << blue.size() << std::endl;
	for (point p: blue) {
		std::cout << p.x << " " << p.y << std::endl;
	}

	line solution = line(0, 0);

	if (algorithm == "naive") {
		solution = naive::solve(red,blue);
	}
	else if (algorithm == "naive_dual") {
		solution = naive_dual::solve(red_dual,blue_dual).dual();
	}
	else if (algorithm == "optimized_naive") {
		solution = optimized_naive::solve(red,blue);
	}
	else if (algorithm == "optimized_naive_dual") {
		solution = optimized_naive_dual::solve(red_dual,blue_dual).dual();
	}
	else if (algorithm == "nlogn_dual") {
		solution = nlogn_dual::solve(red_dual,blue_dual).dual();
	}
	else {
		std::cout << "Invalid algorithm" << std::endl;
		return 0;
	}

	std::cout << solution.m << " " << solution.b << std::endl;

	if (is_solution(solution, red, blue)) {
		std::cout << "Correct answer" << std::endl;
	}
	else {
		std::cout << "Invalid answer" << std::endl;
	}
	
}