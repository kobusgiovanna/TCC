#include <limits>
#include <iostream>
#include "ham_sandwich_point_proposed.hpp"
#include "new_interval_proposed.hpp"
#include "find_trapezoid.hpp"
#include "discard_lines.hpp"
#include "brute_force.hpp"
#include "check_answer.hpp"
#include "odd_level_intersection.hpp"
#include "aux.hpp"
#define eps 1e-8

point ham_sandwich_point_proposed::solve 
(std::vector<line> g1, std::vector<line> g2, int seed) {
	srand(seed);
	if (g1.size()%2 == 0) g1.pop_back(); 	
	if (g2.size()%2 == 0) g2.pop_back();
	std::vector<line> g1l = g1;
	std::vector<line> g2l = g2;
	while (true) {
		int p1 = g1.size()/2;
		int p2 = g2.size()/2;
		g1 = g1l;
		g2 = g2l;
		interval t = interval(std::numeric_limits<double>::lowest(),
			std::numeric_limits<double>::max());
		while (g1.size() > 100 && g2.size() > 100){
			//std::cout<<"new interval"<<std::endl;
			if (g1.size() > g2.size()) {
				std::swap(g1, g2);
				std::swap(p1, p2);
			}
			t = new_interval_proposed::new_interval(g1, g2, p1, p2, t, rand());
			//std::cout<<t.left<<" "<<t.right<<" "<<g1.size()<<" "<<g2.size()<<std::endl;
			trapezoid tau = find_trapezoid::find_trapezoid(g1, p1, t);
			discard_lines::discard_lines(g1, p1, tau);
			if (!odd_level_intersection::odd_level_intersection(g1, g2, p1, p2, t)) break;
			if (p1 >= g1.size() || p2 >= g2.size()) break;
		}
		if(!odd_level_intersection::odd_level_intersection(g1, g2, p1, p2, t)) continue;
		if (p1 >= g1.size() || p2 >= g2.size()) break;
		point answer = brute_force::brute_force(g1, g2, p1, p2, t);
		if (check_answer::check_answer(answer, g1l, g2l)) return answer;
		else std::cout<<"Wrong"<<std::endl;
	}
}
