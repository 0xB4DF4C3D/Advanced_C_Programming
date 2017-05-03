#include<iostream>
#include<sstream>
#include<stdexcept>

#include "Menu.h"

using namespace std;

template<typename TO, typename FROM>
TO numberStringCast(const FROM& from) {
	stringstream ss;
	ss << from;

	TO result;
	ss >> result;

	if (ss.fail() || ss.bad() || !ss.eof())
		throw invalid_argument("[!] Error. The argument must be a number.");

	return result;
}

void Menu::tokenize(const string& str, vector<string>& tokens, const string& delimiters) {

	string::size_type lastPos = str.find_first_not_of(delimiters, 0);

	string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (string::npos != pos || string::npos != lastPos) {

		tokens.push_back(str.substr(lastPos, pos - lastPos));

		lastPos = str.find_first_not_of(delimiters, pos);

		pos = str.find_first_of(delimiters, lastPos);
	}
}


bool Menu::interpret(const std::string & command) {
	vector<string> tokens;

	tokenize(command, tokens);

	if (!tokens.size())
		return EXIT_SUCCESS;

	try {
		if (tokens[0] == "set") {
			if (tokens.size() != 3) throw runtime_error("[!] Error. set needs 2 args"); ;

			if (tokens[1] == "time")
				mBycycleSpeedometer.setTimeMinute(numberStringCast<double>(tokens[2]));
			else if (tokens[1] == "distance")
				mBycycleSpeedometer.setDistanceMile(numberStringCast<double>(tokens[2]));
			else
				throw runtime_error("[!] Error. Can't understand 2nd arg.");
		} else if (tokens[0] == "get") {
			if (tokens.size() != 2) throw runtime_error("[!] Error. get needs 1 args");

			if (tokens[1] == "time")
				cout << "Time taken : " << mBycycleSpeedometer.getTimeMinute();
			else if (tokens[1] == "distance")
				cout << "Distance traveled : " << mBycycleSpeedometer.getDistanceMile();
			else
				throw runtime_error("[!] Error. Can't understand 2nd arg.");
		} else if (tokens[0] == "average") {
			if (tokens.size() != 1) throw runtime_error("[!] Error. move needs no args");

			cout << "Average speed : " << mBycycleSpeedometer.getAverageSpeedMilePerHour();
		} else {
			throw runtime_error("[!] Error. Can't understand.");
		}


	} catch (const exception& e) {
		cout << e.what();
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
