#pragma once

#include<string>
#include<vector>

#include "Weight.h"

class Menu {

private:

	Weight mWeight;

	void tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters = " ");

public:
	bool interpret(const std::string& command);
};