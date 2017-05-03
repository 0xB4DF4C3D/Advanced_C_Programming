#pragma once

#include<string>
#include<vector>

#include "BycycleSpeedometer.h"

class Menu {

private:

	BycycleSpeedometer mBycycleSpeedometer;

	void tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters = " ");

public:
	bool interpret(const std::string& command);
};