#include "Circle.h"
#include <iostream>

using namespace std;

Circle::Circle() {
}


Circle::~Circle() {
}

double Circle::getRadius() const {
	return mRadius;
}

void Circle::setRadius(double radius) {
	if (radius < 0)
		throw std::invalid_argument("[!]Error. Wrong radius. radius must be positive number.");

	mRadius = radius;
}

double Circle::getArea() {
	return getRadius() * getRadius() * PI;
}


double Circle::getDiameter() {
	return 2 * getRadius();
}


double Circle::getCircumference() {
return 2 * getRadius() * PI;
}

