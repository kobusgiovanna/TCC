#include <ctime>
#include <cstdlib>
#include "aux.hpp"

int aux::choose_two(int n){
	return n*(n - 1)/2;
}

point aux::random_intersection(std::vector<line> g, int seed){
	srand(seed);
	int i = rand()%(g.size());
	int j = rand()%(g.size()-1);
	if (j >= i) j++;
	return point(g[i], g[j]);
}