#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape
{
public:
	Square(double& _S, double& _P, double& _side_a, double& _diagonal);

	void printInfo();
private:
	double side_a;
	double diagonal;

	bool validation() override;
};

void square();
#endif // !SQUARE_H