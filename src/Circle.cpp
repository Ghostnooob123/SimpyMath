#include "Circle.h"

Circle::Circle(double& _r, double& _diameter, double& _S, double& _P)
{
	this->setFace(_S);
	this->setTour(_P);
	this->setr(_r);

	this->diameter = _diameter;

	if (!this->validation())
	{
		return;
	}

	if (this->getr() == 0.0)
	{
		if (this->diameter != 0.0)
		{
			this->setr(this->diameter / 2);
		}
		if (this->getTour() != 0.0)
		{
			this->setr(this->getTour() / (2 * M_PI));
		}
		if (this->getFace() != 0.0)
		{
			this->setr(std::round(std::sqrt(this->getFace() / M_PI)));
		}
	}

	this->setTour(2 * M_PI * this->getr());
	this->setFace(M_PI * (this->getr() * this->getr()));

	this->diameter = 2 * this->getr();

	this->shapeCreationStatus(true);
}

void Circle::printInfo()
{
	if (this->getPrecision() == 0)
	{
		std::cout << "S (Face) : " << this->getFace() << '\n';
		std::cout << "P (Circumference): " << this->getTour() << '\n';
		std::cout << '\n';
		std::cout << "r (radius): " << this->getr() << '\n';
		std::cout << '\n';
		std::cout << "d (Diameter): " << this->diameter << '\n';
		std::cout << '\n';

		return;
	}
	std::cout << std::setprecision(this->getPrecision()) << "S (Face) : " << this->getFace() << '\n';
	std::cout << "P (Circumference): " << this->getTour() << '\n';
	std::cout << '\n';
	std::cout << "r (radius): " << this->getr() << '\n';
	std::cout << '\n';
	std::cout << "d (Diameter): " << this->diameter << '\n';

	std::cout.unsetf(std::ios::fixed);
	std::cout.precision(6);
}

bool Circle::validation()
{
	if (this->getr() == 0.0 && this->diameter == 0.0 && this->getFace() == 0.0 && this->getTour() == 0.0)
	{
		std::cout << "Invalid parameters\n";
		this->shapeCreationStatus(false);
		return false;
	}
	return true;
}

void circle()
{
	std::cout << "Enter the given values: \n";
	std::cout << "Example: \n5 \n0 \n0 \n0\n";
	double r = 5.0;
	std::cout << "Enter if you have a given radius: 'r' or left it 0 \n";
	std::cin >> r;
	double d = 0.0;
	std::cout << "Enter if you have a given diameter: 'd' or left it 0 \n";
	std::cin >> d;

	double S = 0.0;
	double P = 0.0;
	std::cout << "Enter if you have a given 'S' (Face) of a circle or left it 0 \n";
	std::cin >> S;
	std::cout << "Enter if you have a given 'P' (Circumference) of a circle or left it 0 \n";
	std::cin >> P;

	if (std::cin.fail())
	{
		return;
	}

	Circle c = Circle(r, d, S, P);

	int precision = 0;
	std::cout << "Decimal precision preference or left it 0\n";
	std::cin >> precision;

	if (c.isShapeDone())
	{
		c.setPrecision(precision);

		std::cout << '\n';
		c.printInfo();
		std::cout << '\n';
	}
}
