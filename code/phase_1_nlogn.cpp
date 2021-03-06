#include <algorithm>
#include <ctime>
#include <iostream>
#include "phase_1_nlogn.hpp"

#define EPS 1e-9
//trocas resp por ans
std::pair<long long, std::pair<int, int>> phase_1_nlogn::inversions
(std::vector<int> &v, int i, int j) {
	if (i == j) return std::make_pair(0, std::make_pair(0, 0));
	int k = (i + j)/2;
	auto ans1 = inversions(v, i, k);
	auto ans2 = inversions(v, k + 1, j);
	auto ans3 = std::make_pair(0, std::make_pair(0, 0));
	int it1 = i, it2 = k + 1;
	std::vector<int> new_v;
	for (int t = i; t <= j; t++){
		if ((it1 <= k && it2 <= j && v[it1] < v[it2]) || it2 > j) {
			new_v.push_back(v[it1++]);
		}
		else {
			ans3.first += k - it1 + 1;
			if(ans3.first > 0) {
				long long r = rand() % (ans3.first);
				if(r < k - it1 + 1){
					ans3.second = std::make_pair(v[it2], v[it1 + r]);
				}
			}
			new_v.push_back(v[it2++]);
		}
	}
	for (int it = 0; it < new_v.size(); it++) v[i + it] = new_v[it];
	std::pair<long long, std::pair<int, int>> ans;
	ans.first = ans1.first + ans2.first + ans3.first;
	if (ans.first == 0) return std::make_pair(0, std::make_pair(0, 0));
	int r = rand() % ans.first;
	if (r < ans1.first) ans.second = ans1.second;
	else if (r < ans1.first + ans2.first) ans.second = ans2.second;
	else ans.second = ans3.second;
	return ans;
}

//tratar qdo n tem 
std::pair<long long, point> phase_1_nlogn::intersections
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
	std::vector<int> pi;
	for (auto x : perm1) pi.push_back(x.second);
	auto aux = inversions(pi, 0, pi.size() - 1);
	if (aux.first == 0) {
		return std::make_pair(0, point(0,0));
	}
	auto inver = aux.second;
	auto inter = point(v[inver.first], v[inver.second]);
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
	line l1 = pth_level(g1, p1, t.left);
	line l2 = pth_level(g2, p2, t.left);
	bool order_left = l1.smaller_eval(l2, t.left);
	l1 = pth_level(g1, p1, t.right);
	l2 = pth_level(g2, p2, t.right);
	bool order_right = l1.smaller_eval(l2, t.right);

	return order_left != order_right;
}

long long phase_1_nlogn::max_intersections(std::vector<line> g1) {
	return (long long)g1.size() * ((long long)g1.size() - 1)/2;
}


//adicionar condicao pra qdo nao tem interseccao num dado intervalo
interval phase_1_nlogn::new_interval 
(std::vector<line> g1, std::vector<line> g2, int p1, int p2, interval t) {
	auto aux = intersections(g1, t);
	int n = aux.first;
	point p = aux.second;
	while (32*n > max_intersections(g1)) {
		//std::cout<<g1.size()<<" "<<g2.size()<<std::endl;
		double pivot = p.x;
		interval t1 = interval(t.left, pivot);
		interval t2 = interval(pivot, t.right);
		if (odd_level_intersection(g1, g2, p1, p2, t1)) t = t1;
		else t = t2;
		aux = intersections(g1, t);
		n = aux.first;
		if (n == 0) break;
		p = aux.second;
	}
	return t;
}