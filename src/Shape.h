#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>

#define _USE_MATH_DEFINES
#include <math.h>

class Shape
{
public:
	double getFace() { return this->S; }
	double getTour() { return this->P; }

	double getH() { return this->h; }

	double getR() { return this->R; }
	double getr() { return this->r; }

	void setFace(double _S) { this->S = _S; }
	void setTour(double _P) { this->P = _P; }

	void setH(double _h) { this->h = _h; }

	void setR(double _R) { this->R = _R; }
	void setr(double _r) { this->r = _r; }

	bool isShapeDone() {
		return shapeCreated;
	}
	void setPrecision(int& newPrecision) {
		this->precision = newPrecision;
	}
protected:
	void shapeCreationStatus(bool status) {
		this->shapeCreated = status;

	}

	int getPrecision() {
		return this->precision;
	}
private:
	double S{ 0.0 };
	double P{ 0.0 };

	double h{ 0.0 };

	double R{ 0.0 };
	double r{ 0.0 };

	int precision{ 0 };

	bool shapeCreated{ false };

	virtual bool validation() {
		return this->isShapeDone();
	}

	//double a{ 0.0 };

	//double radius_r{ 0.0 };
	//double radius_R{ 0.0 };

	//double num_side{ 0.0 }; // Number of sides
};

#endif // !SHAPE_H