
#include "optimized_naive_dual.hpp"

//fix
#include <iostream>
using namespace std;

#define EPS 1e-9

struct optimized_naive_dual::coloured_line {
	line l;
	int id;
	int color;

	coloured_line (line new_l, int new_id, int new_color):
		l(new_l), id(new_id), color(new_color) {}
};

struct optimized_naive_dual::pair_of_lines {
	coloured_line first_line;
	coloured_line second_line;

	pair_of_lines (coloured_line l, coloured_line m):
		first_line(l), second_line(m) {}
};

bool optimized_naive_dual::at_minus_infinity (line l, line m) {
	return l.m > m.m;
}

bool optimized_naive_dual::x_of_intersection
		(pair_of_lines p, pair_of_lines q) {

	point p_intersection = point(p.first_line.l, p.second_line.l);
	point q_intersection = point(q.first_line.l, q.second_line.l);

	return p_intersection.x < q_intersection.x;
}

point optimized_naive_dual::solve (std::vector<line> red,
		std::vector<line> blue, int p1, int p2) {

	//cout<<red.size()<<" "<<blue.size()<<" "<<p1<<" "<<p2<<endl;

	sort(red.begin(), red.end(), at_minus_infinity);
	sort(blue.begin(), blue.end(), at_minus_infinity);

	std::vector<coloured_line> lines;

	std::vector<int> red_position;
	std::vector<int> blue_position;

	for (int i = 0; i < (int)red.size(); i++) {
		lines.push_back(coloured_line(red[i], i, 0));
		red_position.push_back(i);
	}
	for (int i = 0; i < (int)blue.size(); i++) {
		lines.push_back(coloured_line(blue[i], i, 1));
		blue_position.push_back(i);
	}

	std::vector<pair_of_lines> events;

	for (int i = 0; i < (int)lines.size(); i++) {
		for(int j = i+1; j < (int)lines.size(); j++) {
			events.push_back(pair_of_lines(lines[i], lines[j]));
		}
	}

	sort(events.begin(), events.end(), x_of_intersection);

	for (pair_of_lines p: events) {
		if (p.first_line.color == 0 && p.second_line.color == 0) {
			std::swap(red_position[p.first_line.id],
					red_position[p.second_line.id]);
		}
		else if (p.first_line.color == 1 && p.second_line.color == 1) {
			std::swap(blue_position[p.first_line.id], 
					blue_position[p.second_line.id]);
		}
		else{
			if (p.first_line.color == 1) {
				std::swap(p.first_line, p.second_line);
			}
			int red_id = red_position[p.first_line.id];
			if (red_id != p1) {
				continue;
			}
	 		int blue_id = blue_position[p.second_line.id];
			if (blue_id != p2) {
				continue;
			}
			return point(p.first_line.l, p.second_line.l);
		}
	}
	return point(0, 0);	

}

point optimized_naive_dual::solve (std::vector<line> red,
		std::vector<line> blue) {
	if (blue.size()%2 == 0) blue.pop_back();
	if (red.size()%2 == 0) red.pop_back();
	return solve(red, blue, red.size()/2, blue.size()/2);
}