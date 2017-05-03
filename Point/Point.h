#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>
class Point {
public:
	Point();
	~Point();
	double getX() const { return mX; }
	void setX(double x) { mX = x; }
	double getY() const { return mY; }
	void setY(double y) { mY = y; }

	enum class Direction {
		VERTICAL, HORIZONTAL
	};

private:
	double mX;
	double mY;
	
	const int PRECISION = 10000;
	
public:
	void move(Direction direction, double movementAmount);
	void rotateClockwise(double degree);
};

