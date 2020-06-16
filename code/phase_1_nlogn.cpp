#include <algorithm>
#include <ctime>
#include "phase_1_nlogn.hpp"

#define EPS 1e-9

std::pair<long long, std::pair<int, int>> phase_1_nlogn::inversions
(std::vector<int> &v, int i, int j) {
	if (i == j) return std::make_pair(0, std::make_pair(0, 0));
	int k = (i + j)/2;
	auto resp1 = inversions(v, i, k);
	auto resp2 = inversions(v, k + 1, j);
	auto resp3 = std::make_pair(0, std::make_pair(0, 0));
	int it1 = i, it2 = k + 1;
	std::vector<int> new_v;
	while (it1 <= k || it2 <= j) {
		if ((it1 <= k && it2 <= j && v[it1] < v[it2]) || it2 > j) {
			new_v.push_back(v[it1++]);
		}
		else {
			long long r = 0;
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
	std::pair<long long, std::pair<int, int>> resp;
	resp.first = resp1.first + resp2.first + resp3.first;
	if (resp.first == 0) return std::make_pair(0, std::make_pair(0, 0));
	int r = rand() % resp.first;
	if (r < resp1.first) resp.second = resp1.second;
	else if (r < resp1.first + resp2.first) resp.second = resp2.second;
	else resp.second = resp3.second;
	return resp;
}

std::pair<long long, std::pair<int, int>> phase_1_nlogn::inversions
(std::vector<int> v){
	return inversions(v, 0, v.size()-1);
}

std::pair<long long, std::pair<line, line>> phase_1_nlogn::intersections
(std::vector<line> v, interval t) {
	std::sort(v.begin(), v.end(),
		[t](line l, line m){
			return l.smaller_eval(m, t.left);
		}
	);
	std::vector<std::pair<line, int>> perm1;
	for (int i = 0; i < v.size(); i++){
		perm1.push_back(std::make_pair(v[i], i));
	}
	std::sort(perm1.begin(), perm1.end(),
		[t](std::pair<line, int> l, std::pair<line, int> m){
			return l.first.smaller_eval(m.first, t.right);
		}
	);
	std::vector<int> permutation;
	for (auto x : perm1) permutation.push_back(x.second);
	auto aux = inversions(permutation);
	std::pair<line,line> inter =
		std::make_pair(v[aux.second.first], v[aux.second.second]);
	return std::make_pair(aux.first, inter);
}

line phase_1_nlogn::pth_level(std::vector<line> v, int p, double x) {
	std::sort(v.begin(), v.end(), [x](line l, line m){
		return l.smaller_eval(m, x);
	});
	return v[p];
}

bool phase_1_nlogn::odd_level_intersection (std::vector<line> g1,
		std::vector<line> g2, int p1, int p2, interval t) {
	line p1_x1 = pth_level(g1, p1, t.left);
	line p2_x1 = pth_level(g2, p2, t.left);
	line p1_x2 = pth_level(g1, p1, t.right);
	line p2_x2 = pth_level(g2, p2, t.right);
	if(p1_x1.smaller_eval(p2_x1, t.left) ^ 
			p1_x2.smaller_eval(p2_x2, t.right)) {
		return 1;
	}
	return 0;
}

long long phase_1_nlogn::max_intersections(std::vector<line> g1) {
	return (long long)g1.size() * ((long long)g1.size() - 1)/2;
}

std::pair<interval, bool> phase_1_nlogn::new_interval 
(std::vector<line> g1, std::vector<line> g2, int p1, int p2, interval t) {
	if (g2.size() > g1.size()){
		std::swap(g1, g2);
		std::swap(p1, p2);
	}
	if (max_intersections(g1) <= 32) return std::make_pair(t, 1);
	auto aux = intersections(g1, t);
	auto curr_inters = aux.first;
	auto random_inter = aux.second;
	while (32*curr_inters > max_intersections(g1)) {
		double pivot = point(random_inter.first, random_inter.second).x;
		interval t1 = interval(t.left, pivot);
		interval t2 = interval(pivot, t.right);
		if(odd_level_intersection(g1, g2, p1, p2, t1)) t = t1;
		else t = t2;
	}
	return std::make_pair(t, 0);
}