#include "Point.h"

Point::Point() {
	setX(0.0);
	setY(0.0);
}


Point::~Point() {
}


void Point::move(Direction direction, double movementAmount) {
	if(direction == Direction::HORIZONTAL)
		setX(getX() + movementAmount);
	else if(direction == Direction::VERTICAL)
		setY(getY() + movementAmount); 
}

void Point::rotateClockwise(double degree) {

	degree *= M_PI / 180; // Converted to radians.

	// Rotation transformation based on origin.
	double newX = cos(degree)*getX() - sin(degree)*getY();
	double newY = sin(degree)*getX() + cos(degree)*getY();

	// Error correction.
	setX(roundf(newX * PRECISION) / PRECISION);
	setY(roundf(newY * PRECISION) / PRECISION);
}
