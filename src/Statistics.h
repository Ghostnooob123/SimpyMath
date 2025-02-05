#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

const uint8_t MAX_COLS = 4;

double getMaxFrequency(size_t& max_size, std::istringstream& r, std::vector<std::vector<double>>& statistic_table);
void fulfillTheTable(size_t& max_size, double& max_frquency, std::vector<std::vector<double>>& statistic_table);
void tablePrint(size_t& max_size, std::vector<std::vector<double>> statistic_table);
void statistics();

void scatteringCharacteristics();

#endif // !STATISTICS_H