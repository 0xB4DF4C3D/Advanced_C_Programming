#pragma once

#include<string>
#include<vector>

#include "Fraction.h"

class Menu {

private:

	Fraction mFraction;

	void tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters = " ");

public:
	bool interpret(const std::string& command);
};