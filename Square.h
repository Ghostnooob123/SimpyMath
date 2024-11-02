#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape
{
public:
	Square(double& _S, double& _P, double& _side_a, double& _diagonal);

	void printSide() {
		std::cout << "Side a: " << this->side_a << '\n';
	}
	void printDiagonal() {
		std::cout << std::setprecision(4) << "d (Diagonal): " << this->diagonal << '\n';
	}
private:
	double side_a;
	double diagonal;

	bool validation() override;
};

void square();
#endif // !SQUARE_H