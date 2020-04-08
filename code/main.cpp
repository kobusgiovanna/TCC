#include <bits/stdc++.h>

#include "naive.hpp"
#include "naive_dual.hpp"
#include "optimized_naive.hpp"
#include "optimized_naive_dual.hpp"

int main() {

	srand(time(NULL));

	std::cout << std::setprecision(10) << std::fixed;

	std::string algorithm;

	std::cin >> algorithm;

	int red_points = 100;
	int blue_points = 100;

	int max_x = 1000000;
	int min_x = 1000000;

	int max_y = 1000000;
	int min_y = 1000000;	

	std::vector<point> red;
	std::vector<point> blue;

	for (int i = 0; i < red_points; i++) {
		red.push_back(point(rand()%(max_x + min_x) - min_x,
			rand()%(max_y + min_y) - min_y));
	}
	for (int i = 0; i < blue_points; i++) {
		blue.push_back(point(rand()%(max_x + min_x) - min_x,
			rand()%(max_y + min_y) - min_y));
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
		solution = naive_dual::solve(red,blue);
	}
	else if (algorithm == "optimized_naive") {
		solution = optimized_naive::solve(red,blue);
	}
	else if (algorithm == "optimized_naive_dual") {
		solution = optimized_naive_dual::solve(red,blue);
	}
	else {
		std::cout << "Invalid algorithm" << std::endl;
		return 0;
	}

	std::cout << solution.m << " " << solution.b << std::endl;

	if (naive::is_solution(solution, red, blue)) {
		std::cout << "Correct answer" << std::endl;
	}
	else {
		std::cout << "Invalid answer" << std::endl;
	}
	
}