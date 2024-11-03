#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle	: public Shape
{
public:
	Rectangle(double& _S, double& _P, std::vector<double>& _side_arr, double& _diagonal);

	void printInfo();
private:
	std::vector<double> side_arr;
	double diagonal;

	bool validation() override;

	void missingB(double& a, double& b);
	void missingA(double& a, double& b);
};

void rectangle();
#endif // !RECTANGLE_H