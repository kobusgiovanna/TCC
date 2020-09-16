#include <algorithm>
#include <ctime>
#include <iostream>
#include "random_intersection.hpp"

#define EPS 1e-9

std::pair<long long, std::pair<int, int>> random_intersection::inversions
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

std::pair<long long, point> random_intersection::intersections
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