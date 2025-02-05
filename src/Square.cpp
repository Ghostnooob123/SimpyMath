#include "Square.h"

Square::Square(double& _S, double& _P, double& _side_a, double& _diagonal) 
{
	this->setFace(_S);
	this->setTour(_P);

	this->side_a = _side_a;
	this->diagonal = _diagonal;

	if (!this->validation())
	{
		return;
	}

	if (this->side_a == 0.0)
	{
		if (this->getTour() != 0.0)
		{
			this->side_a = this->getTour() / 4;
		}
		if (this->getFace() != 0.0)
		{
			this->side_a = std::round(std::sqrt(this->getFace()));
		}
		if (this->diagonal != 0.0)
		{
			this->side_a = std::round(this->diagonal / std::sqrt(2));
		}
	}

	this->setTour(4 * this->side_a);
	this->setFace(this->side_a * this->side_a);
	this->setR(this->side_a / std::sqrt(2));
	this->setr(this->side_a / 2);

	this->diagonal = this->side_a * std::sqrt(2);

	this->shapeCreationStatus(true);
}

void Square::printInfo()
{
	if (this->getPrecision() == 0)
	{
		std::cout << "S (Face) : " << this->getFace() << '\n';
		std::cout << "P (Circumference): " << this->getTour() << '\n';
		std::cout << '\n';
		std::cout << "Side a: " << this->side_a << '\n';
		std::cout << '\n';
		std::cout << "d (Diagonal): " << this->diagonal << '\n';
		std::cout << '\n';
		std::cout << "R: " << this->getR() << '\n';
		std::cout << "r: " << this->getr() << '\n';

		return;
	}
	std::cout << std::setprecision(this->getPrecision()) << "S (Face) : " << this->getFace() << '\n';
	std::cout << "P (Circumference): " << this->getTour() << '\n';
	std::cout << '\n';
	std::cout << "Side a: " << this->side_a << '\n';
	std::cout << '\n';
	std::cout << "d (Diagonal): " << this->diagonal << '\n';
	std::cout << '\n';
	std::cout  << "R: " << this->getR() << '\n';
	std::cout << "r: " << this->getr() << '\n';

	std::cout.unsetf(std::ios::fixed);
	std::cout.precision(6);
}

bool Square::validation() 
{
    if (this->side_a == 0.0 && this->diagonal == 0.0 && this->getFace() == 0.0 && this->getTour() == 0.0)
    {
        std::cout << "Invalid parameters\n";
        this->shapeCreationStatus(false);
        return false;
    }
    return true;
}

void square() 
{
	std::cout << "Enter the given values: \n";
	std::cout << "Example: \n5 \n0 \n0 \n0\n";
	double side_a = 0.0;
	std::cout << "Enter if you have a given side: 'a' or left it 0 \n";
	std::cin >> side_a;

	double S = 0.0;
	double P = 0.0;

	std::cout << "Enter if you have a given 'S' (Face) of a square or left it 0 \n";
	std::cin >> S;
	std::cout << "Enter if you have a given 'P' (Circumference) of a square or left it 0 \n";
	std::cin >> P;

	double d = 0;
	std::cout << "Enter if you have a given 'd' (Diagonal) of a square or left it 0 \n";
	std::cin >> d;

	if (std::cin.fail())
	{
		return;
	}

	Square s = Square(S, P, side_a, d);

	int precision = 0;
	std::cout << "Decimal precision preference or left it 0\n";
	std::cin >> precision;

	if (s.isShapeDone())
	{
		s.setPrecision(precision);

		std::cout << '\n';
		s.printInfo();
		std::cout << '\n';
	}
}
