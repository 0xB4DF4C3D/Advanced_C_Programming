#include <stdexcept>

#pragma once
class Circle {
public:
	Circle();
	~Circle();


	double getRadius() const; 
	void setRadius(double radius);

private:
	double mRadius;
	const double PI = 3.14159265359;

public:
	double getArea();
	double getDiameter();
	double getCircumference();
};

