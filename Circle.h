#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(double& _r, double& _diagonal, double& _S, double& _P);
	void printInfo();
private:
	double diameter;

	bool validation() override;
};

void circle();
#endif // !CIRCLE_H