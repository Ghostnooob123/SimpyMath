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
        std::cout << std::setprecision(4) << "a: " << this->side_arr[0] << '\n';
        std::cout << std::setprecision(4) << "b: " << this->side_arr[1] << '\n';
        std::cout << std::setprecision(4) << "c: " << this->side_arr[2] << '\n';
    }
    void printHs() {
        std::cout << std::setprecision(4) << "h_a: " << this->h_arr[0] << '\n';
        std::cout << std::setprecision(4) << "h_b: " << this->h_arr[1] << '\n';
        std::cout << std::setprecision(4) << "h_c: " << this->h_arr[2] << '\n';
    }
private:
    std::vector<double> side_arr;
    std::vector<double> h_arr;
    std::vector<double> angle_arr;
    std::vector<double> median_arr;

    void firstWay();
    void secondWay();
};

void triangle();
#endif // !TRIANGLE_H