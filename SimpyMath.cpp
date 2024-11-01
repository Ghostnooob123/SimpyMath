#include <iostream>
#include <string>
#include <sstream>

#include "Triangle.h"
#include "Statistics.h"

int userInput() {
	std::cout << "Available Shapes:\n";
	std::cout << "1: Triangle\n";

	std::cout << "Statistics: \n";
	std::cout << "2: Grouping data into tables with frequency \n";
	std::cout << "3: Scattering characteristic\n";
	std::cout << "0: Exit\n";

	int input = 0;
	while (true) {
		std::cin >> input;

		if (std::cin.fail() || input < 0 || input > 3) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Invalid input. Try again.\n";
		}
		else {
			break;
		}
	}

	return input;
}
int main()
{
	while (userInput() != 0) {
		switch (userInput())
		{
		case 1:
			triangle();
			break;
		case 2:
			statistics();
			break;
		case 3:
			scatteringCharacteristics();
			break;
		case 0:
			break;
		}
	}
}