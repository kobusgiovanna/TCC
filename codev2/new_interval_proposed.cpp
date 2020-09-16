#include <iostream>
#include "new_interval_proposed.hpp"
#include "aux.hpp"
#include "random_intersection.hpp"
#include "odd_level_intersection.hpp"

interval new_interval_proposed::new_interval 
(std::vector<line> g1, std::vector<line> g2, int p1, int p2, 
interval t, int seed) {
	srand(seed);
	bool div = true;
	if (!odd_level_intersection::odd_level_intersection(g1, g2, p1, p2, t)) return t;
	while (div) {
		div = false;
		for (int i = 0; i < g1.size(); i++) {
			double inter = aux::random_intersection(g1,rand()).x;
			//std::cout<<"inter "<<g1.size()<<" "<<t.left<<" "<<t.right<<" "<<inter<<" "<<odd_level_intersection::odd_level_intersection(g1, g2, p1, p2, t)<<std::endl;
			if (t.contains(inter)) {
				//std::cout<<"divide"<<std::endl;
				div = true;
				interval t1 = interval(t.left, inter);
				interval t2 = interval(inter, t.right);
				if (odd_level_intersection::odd_level_intersection(g1, g2, p1, p2, t1)){
					t = t1;
				}
				else if (odd_level_intersection::odd_level_intersection(g1, g2, p1, p2, t2)){
					t = t2;
				}
				else return interval(0,0);
				break;
			}
		}
	}
	std::cout<<"nao divide"<<std::endl;
	return t;
}