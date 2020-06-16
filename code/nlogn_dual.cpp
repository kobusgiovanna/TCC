#include "nlogn_dual.hpp"
#include <cfloat>
#include <iostream>
using namespace std;

point nlogn_dual::solve (std::vector<line> g1, std::vector<line> g2) {
	if (g1.size()%2 == 0) g1.pop_back(); 	
	if (g2.size()%2 == 0) g2.pop_back(); 
	int p1 = g1.size()/2;
	int p2 = g2.size()/2;
	interval t = interval(-1000000000, 1000000000);
	//cout<<"fase 1"<<endl;
	auto next_interval = phase_1_nlogn::new_interval(g1, g2, p1, p2, t);
	while (next_interval.second == 0){
		t = next_interval.first;
		//cout<<"fase 2"<<endl;
		trapezoid tau = 
				phase_2::new_trapezoid(g1, g2, p1, p2, t);
		//cout<<"fase 3"<<endl;
		phase_3::discard_lines(g1, g2, p1, p2, tau);
		//cout<<"fase 1"<<endl;
		next_interval = phase_1_nlogn::new_interval(g1, g2, p1, p2, t);
		//cout<<next_interval.first.left<<" "<<next_interval.first.right<<endl;
	}
	//cout<<"the end"<<endl;
	return optimized_naive_dual::solve(g1, g2, p1, p2);
}
