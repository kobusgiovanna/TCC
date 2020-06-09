
//fix
#include <iostream>
#include <algorithm>
#include <ctime>
#include "phase_1_nlogn.hpp"

#define EPS 1e-9

bool phase_1_nlogn::smaller_eval (line l, line m, double x) {
	if (fabs(l.eval(x) - m.eval(x)) > EPS) {
		return l.eval(x) < m.eval(x);
	}
	return l.m > m.m;
}

std::pair<int,std::pair<int,int>> phase_1_nlogn::inversions_and_random_inversion
(std::vector<int> &v, int i, int j) {
	if (i == j) return std::make_pair(0, std::make_pair(0, 0));
	int k = (i + j)/2;
	auto resp1 = inversions_and_random_inversion(v, i, k);
	auto resp2 = inversions_and_random_inversion(v, k + 1, j);
	auto resp3 = std::make_pair(0, std::make_pair(0, 0));
	int it1 = i, it2 = k + 1;
	std::vector<int> new_v;
	while (it1 <= k || it2 <= j) {
		if ((it1 <= k && it2 <= j && v[it1] < v[it2]) || it2 > j) {
			new_v.push_back(v[it1++]);
		}
		else {
			int r = 0;
			if(resp3.first + k - it1 + 1 > 0) {
				r = rand() % (resp3.first + k - it1 + 1);
			}
			if(r < k - it1 + 1){
				resp3.second = std::make_pair(v[it2], v[it1 + r]);
			}
			resp3.first += k - it1 + 1;
			new_v.push_back(v[it2++]);
		}
	}
	for (int it = 0; it < new_v.size(); it++) v[i + it] = new_v[it];
	std::pair<int,std::pair<int,int>> resp;
	resp.first = resp1.first + resp2.first + resp3.first;
	if (resp.first == 0) return std::make_pair(0, std::make_pair(0, 0));
	int r = rand() % resp.first;
	if (r < resp1.first) resp.second = resp1.second;
	else if (r < resp1.first + resp2.first) resp.second = resp2.second;
	else resp.second = resp3.second;
	return resp;
}

std::pair<int,std::pair<int,int>> phase_1_nlogn::inversions_and_random_inversion
(std::vector<int> v){
	return inversions_and_random_inversion(v, 0, v.size()-1);
}


//remove after testing
int phase_1_nlogn::inversions (std::vector<int> v) {
	return inversions_and_random_inversion(v, 0, v.size()-1).first;
}

std::pair<int, int> phase_1_nlogn::random_inversion (std::vector<int> v) {
	return inversions_and_random_inversion(v, 0, v.size()-1).second;
}

std::pair<int,std::pair<line,line>> 
phase_1_nlogn::intersections_and_random_intersection
(std::vector<line> v, std::pair<double, double> t) {
	std::sort(v.begin(), v.end(),
		[t](line l, line m){
			return smaller_eval(l, m, t.first);
		}
	);
	std::vector<std::pair<line, int>> perm1;
	for (int i = 0; i < v.size(); i++){
		perm1.push_back(std::make_pair(v[i], i));
	}
	std::sort(perm1.begin(), perm1.end(),
		[t](std::pair<line, int> l, std::pair<line, int> m){
			return smaller_eval(l.first, m.first, t.second);
		}
	);
	std::vector<int> permutation;
	for (auto x : perm1) permutation.push_back(x.second);
	auto aux = inversions_and_random_inversion(permutation);
	std::pair<line,line> inter =
		std::make_pair(v[aux.second.first], v[aux.second.second]);
	return std::make_pair(aux.first, inter);
}

int phase_1_nlogn::intersections
(std::vector<line> v, std::pair<double, double> t){
	return intersections_and_random_intersection(v, t).first;
}

std::pair<line,line> phase_1_nlogn::random_intersection
(std::vector<line> v, std::pair<double, double> t){
	return intersections_and_random_intersection(v, t).second;
}

line phase_1_nlogn::pth_level(std::vector<line> v, int p, double x) {
	std::sort(v.begin(), v.end(), [x](line l, line m){
		return smaller_eval(l, m, x);
	});
	return v[p - 1];
}

bool phase_1_nlogn::odd_level_intersection (std::vector<line> g1,
		std::vector<line> g2, int p1, int p2, std::pair<double, double> t) {
	line p1_x1 = pth_level(g1, p1, t.first);
	line p2_x1 = pth_level(g2, p2, t.first);
	line p1_x2 = pth_level(g1, p1, t.second);
	line p2_x2 = pth_level(g2, p2, t.second);
	if(smaller_eval(p1_x1, p2_x1, t.first) ^ 
			smaller_eval(p1_x2, p2_x2, t.second)) {
		return 1;
	}
	return 0;
}

std::pair<double, double> phase_1_nlogn::new_interval (std::vector<line> g1,
		std::vector<line> g2, int p1, int p2, std::pair<double, double> t) {
	if (g2.size() > g1.size()) swap(g1, g2);
	long long initial_intersections = intersections(g1, t);

	while(32*intersections(g1, t) > initial_intersections && 
			intersections(g1,t) > 20) {
		std::pair<line, line> intersection = random_intersection(g1, t);
		double pivot = point(intersection.first, intersection.second).x;
		std::pair<double, double> t1 = std::make_pair(t.first, pivot);
		std::pair<double, double> t2 = std::make_pair(pivot, t.second);
		if(odd_level_intersection(g1, g2, p1, p2, t1)) t = t1;
		else t = t2;
	}
	return t;
}