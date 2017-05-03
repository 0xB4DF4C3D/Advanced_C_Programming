#include "Money.h"
#include <cmath>
using namespace std;

Money::Money() {
	mDollar = 0;
	mCent = 0;
}

Money::Money(double dollarWithCent) {
	setDollarWithCent(dollarWithCent);
}


Money::~Money() {
}


int Money::getDollar() const {
	return mDollar;
}


void Money::setDollar(int dollar) {
	mDollar = dollar;
}


int Money::getCent() const {
	return mCent;
}


void Money::setCent(int cent) {
	mCent = cent;
}

void Money::setDollarWithCent(double dollarWithCent) {
	int dollar = static_cast<int>(floor(abs(dollarWithCent))); // Error correction for negative
	int cent = (abs(dollarWithCent) - dollar) * 100;
	
	mDollar = dollarWithCent < 0 ? -dollar : dollar;
	mCent = dollarWithCent < 0 ? -cent : cent;
}

double Money::getDollarWithCent() const {
	return mDollar + static_cast<double>(mCent)/100;
}
