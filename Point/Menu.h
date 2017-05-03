#pragma once

#include<string>
#include<vector>
#include "Point.h"


class Menu {

private:

	Point mPoint;

	void tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters = " ");

public:
	bool interpret(const std::string& command);
};