#include <iostream>
#include <string>
#include <sstream>

#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"

#include "Statistics.h"

int userInput() {
	std::cout << "Available Shapes:\n";
	std::cout << "1: Triangle\n";
	std::cout << "2: Rectangle\n";
	std::cout << "3: Square\n\n";

	std::cout << "Statistics: \n";
	std::cout << "4: Grouping data into tables with frequency \n";
	std::cout << "5: Scattering characteristic\n";
	std::cout << "0: Exit\n";

	int input = 0;
	while (true) {
		std::cin >> input;

		if (std::cin.fail() || input < 0 || input > 12) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Invalid input. Try again.\n";
		}
		else {
			std::cin.ignore(10000, '\n');
			break;
		}
	}

	return input;
}
int main()
{
	int input = 0;
	do {
		input = userInput();
		std::cout << '\n';

		switch (input) {
		case 1:
			triangle();
			break;
		case 2:
			rectangle();
			break;
		case 3:
			square();
			break;
		case 4:
			statistics();
			break;
		case 5:
			scatteringCharacteristics();
			break;
		case 0:
			std::cout << "See you soon again!\n";
			break;
		}
	} while (input != 0);
}