#pragma once

#include <stdexcept>

class Weight {
public:
	Weight();
	~Weight();
private:
	double mWeightPounds;
public:
	void setWeightPounds(double weight);
	void setWeightKilograms(double weight);
	void setWeightOunces(double weight);
	double getWeightKilograms();
	double getWeightPounds();
	double getWeightOunces();
};

