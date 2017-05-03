#pragma once

#include <iostream>

class BycycleSpeedometer {
public:
	BycycleSpeedometer();
	~BycycleSpeedometer();

	double getDistanceMile() const { return mDistanceMile; }
	void setDistanceMile(double distance);

	double getTimeMinute() const { return mTimeMinute; }
	void setTimeMinute(double time);

private:
	double mDistanceMile;
	double mTimeMinute;
public:
	double getAverageSpeedMilePerHour();
};

