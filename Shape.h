#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>

class Shape
{
public:
	virtual double getFace() { return this->S; }
	virtual double getTour() { return this->P; }
	virtual double getH() { return this->h; }

	void setFace(double _S) { this->S = _S; }
	void setTour(double _P) { this->P = _P; }
	void setH(double _h) { this->h = _h; }

	bool isShapeDone() {
		return shapeCreated;
	}
protected:
	void shapeCreationStatus(bool status) {
		this->shapeCreated = status;

	}
private:
	double S{ 0.0 };
	double P{ 0.0 };

	double h{ 0.0 };

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