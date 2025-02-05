#include "Rectangle.h"

Rectangle::Rectangle(double& _S, double& _P, std::vector<double>& _side_arr, double& _diagonal) {
	this->setFace(_S);
	this->setTour(_P);

	this->side_arr = _side_arr;
	this->diagonal = _diagonal;

	double a = this->side_arr[0];
	double b = this->side_arr[1];

	if (!this->validation())
	{
		return;
	}

	missingA(a, b);
	missingB(a, b);

	this->setTour(2 * (a + b));
	this->setFace(a * b);

	this->diagonal = std::sqrt((a * a) + (b * b));

	this->setR(this->diagonal * 2);

	this->side_arr[0] = a;
	this->side_arr[1] = b;

	this->shapeCreationStatus(true);
}

void Rectangle::printInfo()
{
	if (this->getPrecision() == 0)
	{
		std::cout << "S (Face) : " << this->getFace() << '\n';
		std::cout << "P (Circumference): " << this->getTour() << '\n';
		std::cout << '\n';

		std::cout << "Side a: " << this->side_arr[0] << '\n'
			<< "Side b: " << this->side_arr[1] << '\n';
		std::cout << '\n';
		std::cout << "d (Diagonal): " << this->diagonal << '\n';
		std::cout << '\n';
		std::cout << "R: " << this->getR() << '\n';

		return;
	}
	std::cout << std::setprecision(this->getPrecision()) << "S (Face) : " << this->getFace() << '\n';
	std::cout << "P (Circumference): " << this->getTour() << '\n';
	std::cout << '\n';
	std::cout << "Side a: " << this->side_arr[0] << '\n'
		<< "Side b: " << this->side_arr[1] << '\n';
	std::cout << '\n';
	std::cout << "d (Diagonal): " << this->diagonal << '\n';
	std::cout << '\n';
	std::cout << "R: " << this->getR() << '\n';

	std::cout.unsetf(std::ios::fixed);
	std::cout.precision(6);
}

bool Rectangle::validation() {
	size_t times = 0;
	for (size_t i = 0; i < this->side_arr.size(); i++)
	{
		if (this->side_arr[i] == 0.0)
		{
			times++;
		}
	}
	if (times >= 2)
	{
		std::cout << '\n';
		std::cout << "Invalid parameters\n";
		this->shapeCreationStatus(false);
		std::cout << '\n';
		return false;
	}

	return true;
}
void Rectangle::missingB(double& a, double& b) {
	if (a == 0.0)
	{
		if (this->getTour() != 0.0)
		{
			a = (this->getTour() / 2) - b;
		}
		if (this->getFace() != 0.0)
		{
			a = this->getFace() / b;
		}
		if (this->diagonal != 0.0)
		{
			a = std::round(std::sqrt((this->diagonal * this->diagonal) - (b * b)));
		}
	}
}
void Rectangle::missingA(double& a, double& b) {
	if (b == 0.0)
	{
		if (this->getTour() != 0.0)
		{
			b = (this->getTour() / 2) - a;
		}
		if (this->getFace() != 0.0)
		{
			b = this->getFace() / a;
		}
		if (this->diagonal != 0.0)
		{
			b = std::round(std::sqrt((this->diagonal * this->diagonal) - (a * a)));
		}
	}
}

void rectangle() {
	std::cout << "Enter the given values: \n";
	std::cout << "Example: \n6 4 \n0 \n0 \n0\n";
	double a = 0.0;
	double b = 0.0;
	std::cout << "Enter if you have a given side: 'a', 'b' or left it 0 \n";
	std::cin >> a >> b;
	std::vector<double> v{ a, b };

	double S = 0.0;
	double P = 0.0;
	std::cout << "Enter if you have a given 'S' (Face) of a rectangle or left it 0 \n";
	std::cin >> S;
	std::cout << "Enter if you have a given 'P' (Circumference) of a rectangle or left it 0 \n";
	std::cin >> P;

	double d = 0;
	std::cout << "Enter if you have a given 'd' (Diagonal) of a rectangle or left it 0 \n";
	std::cin >> d;

	if (std::cin.fail())
	{
		return;
	}

	Rectangle r = Rectangle(S, P, v, d);

	int precision = 0;
	std::cout << "Decimal precision preference or left it 0\n";
	std::cin >> precision;

	if (r.isShapeDone())
	{
		r.setPrecision(precision);

		std::cout << '\n';
		r.printInfo();
		std::cout << '\n';
	}
}