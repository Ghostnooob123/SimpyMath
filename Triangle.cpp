#include "Triangle.h"

Triangle::Triangle(std::vector<double>& _side_arr, std::vector<double>& _h_arr, std::vector<double>& _angle_arr, double& _S, double& _P)
{
    this->setFace(_S);
    this->setTour(_P);

    this->side_arr = _side_arr;
    this->h_arr = _h_arr;
    this->angle_arr = _angle_arr;

    if (!this->validation())
    {
        return;
    }

    size_t index = 0;
    double sum = 0.0;

    if (this->angle_arr[0] == 0.0 && this->angle_arr[1] == 0.0 && this->angle_arr[2] == 0.0)
    {
        for (size_t i = 0; i < this->side_arr.size(); i++)
        {
            if (this->side_arr[i] != 0.0)
            {
                sum += this->side_arr[i] * this->side_arr[i];
            }
            else
            {
                index = i;
            }
        }

        this->side_arr[index] = std::sqrt(sum);
    }

    if (this->getFace() != 0.0)
    {
        for (size_t i = 0; i < this->h_arr.size(); i++)
        {
            this->h_arr[i] = (2 * this->getFace()) / this->side_arr[i];
        }

        this->secondWay();
    }
    else
    {
        if (this->angle_arr[0] != 0.0 || this->angle_arr[1] != 0.0 || this->angle_arr[2] != 0.0) {
            this->firstWay();
        }
        if (this->h_arr[0] != 0.0 || this->h_arr[1] != 0.0 || this->h_arr[2] != 0.0)
        {
            for (size_t i = 0; i < this->h_arr.size(); i++)
            {
                if (this->h_arr[i] != 0.0)
                {
                    this->setFace(0.5 * this->side_arr[i] * this->h_arr[i]);

                }
            }

            this->secondWay();
        }
        if (this->side_arr[0] != 0.0 && this->side_arr[1] != 0.0 && this->side_arr[2] != 0.0)
        {
            double p = (this->side_arr[0] + this->side_arr[1] + this->side_arr[2]) / 2;
            this->setFace(std::sqrt(p * (p - this->side_arr[0]) * (p - this->side_arr[1]) * (p - this->side_arr[2])));
        }

        for (size_t i = 0; i < this->h_arr.size(); i++)
        {
            this->h_arr[i] = (2 * this->getFace()) / this->side_arr[i];
        }
    }

    if (this->getTour() == 0.0)
    {
        this->setTour(this->side_arr[0] + this->side_arr[1] + this->side_arr[2]);
    }

    this->medians();

    this->shapeCreationStatus(true);
}

bool Triangle::validation()
{
    size_t times = 0;
    for (size_t i = 0; i < this->side_arr.size(); i++)
    {
        if (this->side_arr[i] == 0.0)
        {
            times++;
        }
    }
    if (times >= 2)
    {
        std::cout << '\n';
        std::cout << "Invalid parameters\n";
        this->shapeCreationStatus(false);
        std::cout << '\n';
        return false;
    }

    return true;
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
void Triangle::medians() {
    double a = this->side_arr[0] * this->side_arr[0];
    double b = this->side_arr[1] * this->side_arr[1];
    double c = this->side_arr[2] * this->side_arr[2];

    this->median_arr.resize(3);
    this->median_arr[0] = 0.5 * std::sqrt(2 * b + 2 * c - a);
    this->median_arr[1] = 0.5 * std::sqrt(2 * a + 2 * c - b);
    this->median_arr[2] = 0.5 * std::sqrt(2 * a + 2 * b - c);
  }

void triangle() {
    std::cout << "Enter the given values: \n";
    std::cout << "Example: \n12 5 0 \n0 0 0 \n0 0 30 \n0 \n0\n";
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    std::cout << "Enter if you have a given side: 'a', 'b' and 'ç' or left it 0 \n";
    std::cin >> a >> b >> c;

    double h_a = 0.0;
    double h_b = 0.0;
    double h_c = 0.0;

    std::cout << "Enter if you have a given h: 'h_a', 'h_b' and 'h_c' or left it 0 \n";
    std::cin >> h_a >> h_b >> h_c;

    double angle_a = 0.0;
    double angle_b = 0.0;
    double angle_c = 0.0;

    std::cout << "Enter if you have a given angle: 'Alpha', 'Beta' and 'Gamma' or left it 0 \n";
    std::cin >> angle_a >> angle_b >> angle_c;

    std::vector<double> side_arr{ a, b, c };
    std::vector<double> h_arr{ h_a, h_b, h_c };
    std::vector<double> angle_arr{ angle_a, angle_b, angle_c };

    double S = 0.0;
    double P = 0.0;

    std::cout << "Enter if you have a given 'S' (Face) of a triangle or left it 0 \n";
    std::cin >> S;
    std::cout << "Enter if you have a given 'P' (Circumference) of a triangle or left it 0 \n";
    std::cin >> P;

    if (std::cin.fail())
    {
        return;
    }

    std::cout << '\n';

    Triangle t = Triangle(side_arr, h_arr, angle_arr, S, P);

    if (t.isShapeDone())
    {
        std::cout << "S (Face) : " << t.getFace() << '\n';
        std::cout << "P (Circumference): " << t.getTour() << '\n';
        std::cout << '\n';
        t.printSides();
        std::cout << '\n';
        t.printHs();
        std::cout << '\n';
        t.printMedians();
        std::cout << '\n';
    }
}


/*

12 5 0 0 0 0 0 30 0 0 0

*/