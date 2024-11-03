#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
public:
    Triangle(std::vector<double>& _side_arr, std::vector<double>& _h_arr, std::vector<double>& _angle_arr, double& _S, double& _P);

    void printInfo();
private:
    std::vector<double> side_arr;
    std::vector<double> h_arr;
    std::vector<double> angle_arr;
    std::vector<double> median_arr;

    bool validation() override;

    void firstWay();
    void secondWay();
    void medians();
};

void triangle();
#endif // !TRIANGLE_H