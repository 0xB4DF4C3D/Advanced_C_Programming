#include "BycycleSpeedometer.h"

using namespace std;

BycycleSpeedometer::BycycleSpeedometer() {
	mDistanceMile = 0.0;
	mTimeMinute = 0.0;
}


BycycleSpeedometer::~BycycleSpeedometer() {
}


void BycycleSpeedometer::setDistanceMile(double distance) {
	if (distance < 0)
		throw invalid_argument("[!] Error. distance must be positive number.");

	mDistanceMile = distance;
}


void BycycleSpeedometer::setTimeMinute(double time) {
	if (time < 0)
		throw invalid_argument("[!] Error. time must be positive number.");

	mTimeMinute = time;
}


double BycycleSpeedometer::getAverageSpeedMilePerHour() {
	double TimeHour = getTimeMinute() / 60;
	double AverageSpeedMilePerHour = getDistanceMile() / TimeHour;

	return AverageSpeedMilePerHour;
}
