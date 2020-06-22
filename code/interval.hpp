#ifndef INTERVAL_H 
#define INTERVAL_H

class interval {

	public:

		double left, right;

		interval (double left, double right);

		bool contains (double x);

};

#endif