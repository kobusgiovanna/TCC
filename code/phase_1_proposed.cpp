#include <algorithm>
#include <ctime>
#include "phase_1_proposed.hpp"

#define EPS 1e-9

point phase_1_proposed::random_intersection
(std::vector<line> &g) {
	srand(time(NULL));
	int i = rand()%(g.size());
	int j = rand()%(g.size()-1);
	if (j >= i) j++;
	return point(g[i], g[j]);
}


//adicionar condicao pra qdo nao tem interseccao num dado intervalo
interval phase_1_proposed::new_interval 
(std::vector<line> g1, std::vector<line> g2, int p1, int p2, interval t) {
	double alpha = 1./32;
	bool div = true;
	while (div) {
		div = false;
		for (int i = 0; i < g1.size(); i++) {
			double inter = random_intersection(g1);
			
		}
	}

}