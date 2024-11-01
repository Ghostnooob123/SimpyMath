#include "Triangle.h"

Triangle::Triangle(std::vector<double>& _side_arr, std::vector<double>& _h_arr, std::vector<double>& _angle_arr, double& _S, double& _P)
{
    this->setFace(_S);
    this->setTour(_P);

    this->side_arr = _side_arr;
    this->h_arr = _h_arr;
    this->angle_arr = _angle_arr;

    if (this->angle_arr[0] != 0.0 || this->angle_arr[1] != 0.0 || this->angle_arr[2] != 0.0) {
        this->firstWay();
    }
    else
    {
        this->secondWay();
    }

    if (this->getFace() == 0.0)
    {
        double p = (this->side_arr[0] + this->side_arr[1] + this->side_arr[2]) / 2;
        this->setFace(std::sqrt(p * (p - this->side_arr[0]) * (p - this->side_arr[1]) * (p - this->side_arr[2])));
    }

    for (size_t i = 0; i < this->h_arr.size(); i++)
    {
        this->h_arr[i] = (2 * this->getFace()) / this->side_arr[i];
    }
    /*for (size_t i = 0; i < this->h_arr.size(); i++)
    {
        if (this->h_arr[i] == 0.0 && this->side_arr[i] != 0.0)
        {
            this->h_arr[i] = (2 * this->getFace()) / this->side_arr[i];
        }
    }*/

    if (this->getTour() == 0.0)
    {
        this->setTour(this->side_arr[0] + this->side_arr[1] + this->side_arr[2]);
    }
    if (this->getH() == 0.0)
    {
        this->setH((2 * this->getTour()) / this->side_arr[0]);
    }
}

void Triangle::firstWay()
{
    double radians = 0.0;
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    if (this->side_arr[0] == 0.0 && this->angle_arr[0] != 0.0)
    {
        b = this->side_arr[1] * this->side_arr[1];
        c = this->side_arr[2] * this->side_arr[2];

        radians = this->angle_arr[0] * (M_PI / 180.0);

        this->side_arr[0] = std::sqrt(b + c - (2 * this->side_arr[1] * this->side_arr[2] * this->angle_arr[0]));
    }
    if (this->side_arr[1] == 0.0 && this->angle_arr[1] != 0)
    {
        a = this->side_arr[0] * this->side_arr[0];
        c = this->side_arr[2] * this->side_arr[2];

        radians = this->angle_arr[1] * (M_PI / 180.0);

        this->side_arr[1] = std::sqrt(a + c - (2 * this->side_arr[0] * this->side_arr[2] * std::cos(radians)));
    }
    if (this->side_arr[2] == 0.0 && this->angle_arr[2] != 0)
    {
        a = this->side_arr[0] * this->side_arr[0];
        b = this->side_arr[1] * this->side_arr[1];

        radians = this->angle_arr[2] * (M_PI / 180.0);

        this->side_arr[2] = std::sqrt(a + b - (2 * this->side_arr[0] * this->side_arr[1] * std::cos(radians)));
    }
}
void Triangle::secondWay()
{
    {
        double sin = 0.0;

        double a = 0.0;
        double b = 0.0;
        double c = 0.0;
        if (this->side_arr[0] == 0.0)
        {
            sin = (2 * this->getFace()) / (this->side_arr[1] * this->side_arr[2]);
            this->angle_arr[0] = std::sqrt(1 - (sin * sin));
            b = this->side_arr[1] * this->side_arr[1];
            c = this->side_arr[2] * this->side_arr[2];

            this->side_arr[0] = std::sqrt(b + c - (2 * this->side_arr[1] * this->side_arr[2] * this->angle_arr[0]));
        }
        if (this->side_arr[1] == 0.0)
        {
            sin = (2 * this->getFace()) / (this->side_arr[0] * this->side_arr[2]);
            this->angle_arr[1] = std::sqrt(1 - (sin * sin));

            a = this->side_arr[0] * this->side_arr[0];
            c = this->side_arr[2] * this->side_arr[2];

            this->side_arr[1] = std::sqrt(a + c - (2 * this->side_arr[0] * this->side_arr[2] * this->angle_arr[1]));
        }
        if (this->side_arr[2] == 0.0)
        {
            sin = (2 * this->getFace()) / (this->side_arr[0] * this->side_arr[1]);
            this->angle_arr[2] = std::sqrt(1 - (sin * sin));

            a = this->side_arr[0] * this->side_arr[0];
            b = this->side_arr[1] * this->side_arr[1];

            this->side_arr[2] = std::sqrt(a + b - (2 * this->side_arr[0] * this->side_arr[1] * this->angle_arr[2]));
        }
    }
}

void triangle() {
    std::cout << "Enter the given values: \n";
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    std::cout << "Enter if you have a given side: a, b and c or left it 0 \n";
    std::cin >> a >> b >> c;

    double h_a = 0.0;
    double h_b = 0.0;
    double h_c = 0.0;

    std::cout << "Enter if you have a given h: h_a, h_b and h_c or left it 0 \n";
    std::cin >> h_a >> h_b >> h_c;

    double angle_a = 0.0;
    double angle_b = 0.0;
    double angle_c = 0.0;

    std::cout << "Enter if you have a given angle: Alpha, Beta and Gamma or left it 0 \n";
    std::cin >> angle_a >> angle_b >> angle_c;

    std::vector<double> side_arr{ a, b, c };
    std::vector<double> h_arr{ h_a, h_b, h_c };
    std::vector<double> angle_arr{ angle_a, angle_b, angle_c };

    double S = 0;
    double P = 0.0;

    std::cout << "Enter if you have a given face of a triangle or left it 0 \n";
    std::cin >> S;
    std::cout << "Enter if you have a given circumference of a triangle or left it 0 \n";
    std::cin >> P;

    if (std::cin.fail())
    {
        return;
    }

    std::cout << '\n';

    Triangle t = Triangle(side_arr, h_arr, angle_arr, S, P);

    std::cout << "S: " << t.getFace() << '\n';
    std::cout << "P: " << t.getTour() << '\n';
    std::cout << '\n';
    t.printSides();
    std::cout << '\n';
    t.printHs();
    std::cout << '\n';
    std::cout << "h: " << t.getH() << '\n';
}