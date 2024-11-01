#include "Statistics.h"

double getMaxFrequency(size_t& max_size, std::istringstream& r, std::vector<std::vector<double>>& statistic_table) {
	double frequency = 0;
	double frequency_max = 0;

	std::vector<double> v;

	while (r >> frequency)
	{
		frequency_max += frequency;
		v.push_back(frequency);
		max_size++;
	}

	statistic_table.resize(MAX_COLS);
	for (size_t i = 0; i < statistic_table.size(); i++)
	{
		statistic_table[i].resize(max_size);
	}

	statistic_table[0] = v;

	return frequency_max;
}
void fulfillTheTable(size_t& max_size, double& max_frquency, std::vector<std::vector<double>>& statistic_table) {
	double fruquency = std::round(statistic_table[0][0] * 100.0) / 100.0;

	for (size_t x = 0; x < MAX_COLS; x++)
	{
		for (size_t y = 0; y < max_size; y++)
		{
			switch (x)
			{
			case 1:
				statistic_table[x][y] = /*statistic_table[0][y] / max_frquency*/ std::round((statistic_table[0][y] / max_frquency) * 100.0) / 100.0;
				break;
			case 2:
			{
				if (y == 0)
				{
					statistic_table[x][y] = fruquency;
					break;
				}
				statistic_table[x][y] = fruquency + statistic_table[0][y];
				fruquency += statistic_table[0][y];
			}
			break;
			case 3:
				statistic_table[x][y] = /*statistic_table[2][y] / max_frquency*/ std::round((statistic_table[2][y] / max_frquency) * 1000.0) / 1000.0;
				break;
			}
		}
	}
}
void tablePrint(size_t& max_size, std::vector<std::vector<double>> statistic_table) {
	for (size_t x = 0; x < max_size; x++)
	{
		for (size_t y = 0; y < statistic_table.size(); y++)
		{
			std::cout << std::setprecision(5) << statistic_table[y][x];
			if (statistic_table[y][x] < 9)
			{
				std::cout << "          ";
				continue;
			}
			std::cout << "         ";
		}
		std::cout << '\n';
	}
}
void statistics() {
	std::cout << "Enter the given frequency: (Example: 2 5 12 33 67 8 4)\n";
	std::string input_data = "";
	std::getline(std::cin, input_data);

	std::istringstream r(input_data);

	std::vector<std::vector<double>> statistic_table = {};
	size_t max_size = 0;

	double frequency_max = getMaxFrequency(max_size, r, statistic_table);

	fulfillTheTable(max_size, frequency_max, statistic_table);

	std::cout << "\nTable: \n";
	tablePrint(max_size, statistic_table);

	std::cout << "\nMax frequency: " << frequency_max << '\n';

	double relative_requency = 0.0;

	for (size_t y = 0; y < max_size; y++)
	{
		relative_requency += statistic_table[1][y];
	}

	std::cout << "Relative frequency: " << relative_requency << '\n';
	std::cout << '\n';
}

void scatteringCharacteristics() {
	std::cout << "Enter the given data: (Example: 12 10 15 15)\n";
	std::string input = "";
	std::getline(std::cin, input);

	std::istringstream r(input);
	double avg = 0.0;
	double cur_num = 0.0;
	double times = 0.0;

	std::vector<double> v;

	double min = INT_MAX;
	double max = INT_MIN;

	// AVERAGE
	while (r >> cur_num) {
		avg += cur_num;
		if (min > cur_num)
		{
			min = cur_num;
		}
		if (max < cur_num)
		{
			max = cur_num;
		}
		v.push_back(cur_num);
		times++;
	}

	std::cout << '\n';

	avg /= times;
	std::cout << std::setprecision(3) << "Average: " << avg << '\n';

	// SWING
	double swing = static_cast<double>(max - min);
	std::cout << std::setprecision(3) << "Swing: " << swing << '\n';
	//TODO: ADD GRAPHIC for 2 or more inputs.

	// DISPERSION
	std::vector<double> dispersion_arr;
	for (auto& num : v) {
		dispersion_arr.push_back(num - avg);
	}
	v.clear();

	double dispersion = 0.0;
	for (auto& num : dispersion_arr) {
		dispersion += num * num;
	}

	dispersion /= times;
	std::cout << std::setprecision(3) << "Dispersion: " << dispersion << '\n';

	// STANDARD DEVIATION
	double standart_deviattion = dispersion;
	std::cout << std::setprecision(3) << "Standart Deviattion: " << std::sqrt(standart_deviattion) << '\n';
	dispersion_arr.clear();
	std::cout << '\n';

	/*

	47 95 10 65 90 60 81 77
	20 10 15 15
	5.5 6 4.5 4.5 5 5.5 5 4

	*/
}