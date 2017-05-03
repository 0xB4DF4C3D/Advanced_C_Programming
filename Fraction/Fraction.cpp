#include "Fraction.h"

using namespace std;

unsigned int gcd(unsigned int n1, unsigned int n2) {
	unsigned int tmp;
	while (n2 != 0) {
		tmp = n1;
		n1 = n2;
		n2 = tmp % n2;
	}
	return n1;
}

Fraction::Fraction() {
	mNumerator = 0;
	mDenominator = 0;
}


Fraction::~Fraction() {
}


double Fraction::getDecimal() {
	if (getDenominator() == 0)
		throw logic_error("[!] Error. Denominator is 0");

	return static_cast<double>(getNumerator()) / getDenominator();
}


bool Fraction::printLowestTerm() {
	unsigned int divisor = gcd(getNumerator(), getDenominator());
	if (divisor == 0)
		throw logic_error("[!] Error. Denominator is 0");
	
	cout << getNumerator() << " / " << getDenominator() << " => "  
		<< getNumerator() / divisor << " / " << getDenominator() / divisor;
	return false;
}
