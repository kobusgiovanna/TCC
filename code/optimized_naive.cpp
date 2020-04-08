
#include "optimized_naive.hpp"

#define EPS 1e-9

//dualled
struct optimized_naive::coloured_point {
	point p;
	int id;
	int color;

	coloured_point (point new_p, int new_id, int new_color):
		p(new_p), id(new_id), color(new_color) {}
};

//dualled
struct optimized_naive::pair_of_points {
	coloured_point first_point;
	coloured_point second_point;

	pair_of_points (coloured_point p, coloured_point q):
		first_point(p), second_point(q) {}
};

//dualled change name later
bool optimized_naive::x_coordinate (point p, point q) {
	return p.x < q.x;
}

//dualled change name later
bool optimized_naive::slope_of_connecting_line
		(pair_of_points p, pair_of_points q) {

	line p_line = line(p.first_point.p, p.second_point.p);
	line q_line = line(q.first_point.p, q.second_point.p);

	return p_line.m < q_line.m;
}

line optimized_naive::solve (std::vector<point> red, 
		std::vector<point> blue) {

	sort(red.begin(), red.end(), x_coordinate);
	sort(blue.begin(), blue.end(), x_coordinate);

	std::vector<coloured_point> points;

	std::vector<int> red_position;
	std::vector<int> blue_position;

	for (int i = 0; i < red.size(); i++) {
		points.push_back(coloured_point(red[i], i, 0));
		red_position.push_back(i);
	}
	for (int i = 0; i < blue.size(); i++) {
		points.push_back(coloured_point(blue[i], i, 1));
		blue_position.push_back(i);
	}

	std::vector<pair_of_points> events;

	for (int i = 0; i < points.size(); i++) {
		for(int j = i+1; j < points.size(); j++) {
			events.push_back(pair_of_points(points[i], points[j]));
		}
	}

	sort(events.begin(), events.end(), slope_of_connecting_line);

	for (pair_of_points p: events) {
		if (p.first_point.color == 0 && p.second_point.color == 0) {
			std::swap(red_position[p.first_point.id],
					red_position[p.second_point.id]);
		}
		else if (p.first_point.color == 1 && p.second_point.color == 1) {
			std::swap(blue_position[p.first_point.id], 
					blue_position[p.second_point.id]);
		}
		else{
			if (p.first_point.color == 1) {
				std::swap(p.first_point, p.second_point);
			}
			int red_id = red_position[p.first_point.id];
			if (red_id < (red.size()-1)/2 || red_id > red.size()/2) {
				continue;
			}
	 		int blue_id = blue_position[p.second_point.id];
			if (blue_id<(blue.size()-1)/2 || blue_id>blue.size()/2) {
				continue;
			}
			return line(p.first_point.p, p.second_point.p);
		}
	}	
}