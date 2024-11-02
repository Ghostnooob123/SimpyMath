#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>

#define _USE_MATH_DEFINES
#include <math.h>

class Triangle : public Shape
{
public:
    Triangle(std::vector<double>& _side_arr, std::vector<double>& _h_arr, std::vector<double>& _angle_arr, double& _S, double& _P);

    void printSides() {
        std::cout << std::setprecision(4) << "Side a: " << this->side_arr[0] << '\n';
        std::cout << std::setprecision(4) << "Side b: " << this->side_arr[1] << '\n';
        std::cout << std::setprecision(4) << "Side c: " << this->side_arr[2] << '\n';
    }
    void printHs() {
        std::cout << std::setprecision(4) << "Heigh h_a: " << this->h_arr[0] << '\n';
        std::cout << std::setprecision(4) << "Height h_b: " << this->h_arr[1] << '\n';
        std::cout << std::setprecision(4) << "Height h_c: " << this->h_arr[2] << '\n';
    }
    void printMedians() {
        std::cout << std::setprecision(4) << "Median m_a: " << this->median_arr[0] << '\n';
        std::cout << std::setprecision(4) << "Median m_b: " << this->median_arr[1] << '\n';
        std::cout << std::setprecision(4) << "Median m_c: " << this->median_arr[2] << '\n';
    }
private:
    std::vector<double> side_arr;
    std::vector<double> h_arr;
    std::vector<double> angle_arr;
    std::vector<double> median_arr;

    void firstWay();
    void secondWay();
    void medians();
};

void triangle();
#endif // !TRIANGLE_H