#pragma once

#include<iostream>

class Fraction {
public:
	Fraction();
	~Fraction();
	
	void setNumerator(int numerator) { mNumerator = numerator; }
	void setDenominator(int denominator) { mDenominator = denominator; }

	int getNumerator() const { return mNumerator; }
	int getDenominator() const { return mDenominator; }

private:
	int mNumerator;
	int mDenominator;

public:
	double getDecimal();
	bool printLowestTerm();
};

