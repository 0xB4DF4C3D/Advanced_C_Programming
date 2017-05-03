#include "Weight.h"

using namespace std;

Weight::Weight() {
	mWeightPounds = 0.0;
}


Weight::~Weight() {
}


void Weight::setWeightPounds(double weight) {
	if (weight < 0)
		throw invalid_argument("[!] Error. weight must be positive number.");
	mWeightPounds = weight;
}


void Weight::setWeightKilograms(double weight) {
	if (weight < 0)
		throw invalid_argument("[!] Error. weight must be positive number.");
	mWeightPounds = weight * 2.21;
}


void Weight::setWeightOunces(double weight) {
	if (weight < 0)
		throw invalid_argument("[!] Error. weight must be positive number.");
	mWeightPounds = weight / 16;
}

double Weight::getWeightPounds() {
	return mWeightPounds;
}


double Weight::getWeightKilograms() {
	return mWeightPounds / 2.21;
}


double Weight::getWeightOunces() {
	return mWeightPounds * 16;
}
