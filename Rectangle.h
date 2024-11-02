#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle	: public Shape
{
public:
	Rectangle(double& _S, double& _P, std::vector<double>& _side_arr, double& _diagonal);

	void printDiagonal() {
		std::cout << std::setprecision(4) << "d (Diagonal): " << this->diagonal << '\n';
	}
	void printSides() {
		std::cout << std::setprecision(4) << "Side a: " << this->side_arr[0] << '\n';
		std::cout << std::setprecision(4) << "Side b: " << this->side_arr[1] << '\n';
	}
private:
	std::vector<double> side_arr;
	double diagonal;

	bool validation() override;

	void missingB(double& a, double& b);
	void missingA(double& a, double& b);
};

void rectangle();
#endif // !RECTANGLE_H