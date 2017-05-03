#include <iostream>
#include "Circle.h"

using namespace std;

int main() {

	Circle myCircle;
	double radius;

	cout << "This is a program for testing Circle class.." << endl;
	cout << "If the input is 0, it ends." << endl << endl;

	// Decimal point accuracy adjustment.
	cout.setf(ios::fixed);
	cout.precision(8);

	do { // Repeat until 0 is input.
		cout << "Input radius of a circle : ";
		if (!(cin >> radius)) {
			cout << "[!]Error. Wrong input." << endl << endl;
			cin.clear(); cin.ignore(INT_MAX, '\n');
			continue;
		}
			
		if (radius == 0) // If input is 0, exit.
			break;

		try {
			myCircle.setRadius(radius);

			cout << "Area of a circle : " << myCircle.getArea() << endl;
			cout << "Diameter of a circle : " << myCircle.getDiameter() << endl;
			cout << "Circumference of a circle : " << myCircle.getCircumference() << endl;
		} catch (const exception& e) {
			cout << e.what() << endl << endl;
		}

		cout << endl;
	} while (true);

	cout << "\nEnd testing. bye.." << endl;


	return EXIT_SUCCESS;
}