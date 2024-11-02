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
	this->diagonal = this->side_a * std::sqrt(2);

	this->shapeCreationStatus(true);
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

	double S = 0;
	double P = 0.0;

	std::cout << "Enter if you have a given 'S' (Face) of a square or left it 0 \n";
	std::cin >> S;
	std::cout << "Enter if you have a given 'P' (Circumference) of a square or left it 0 \n";
	std::cin >> P;

	double d = 0;
	std::cout << "Enter if you have a given 'd' (Diagonal) of a square or left it 0 \n";
	std::cin >> d;

	Square s = Square(S, P, side_a, d);

	if (s.isShapeDone())
	{
		std::cout << '\n';
		s.printSide();
		std::cout << '\n';
		std::cout << "S (Face):" << s.getFace() << '\n';
		std::cout << "P (Circumference): " << s.getTour() << '\n';
		std::cout << '\n';
		s.printDiagonal();
		std::cout << '\n';
	}
}
