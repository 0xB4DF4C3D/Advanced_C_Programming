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
		throw invalid_argument("[!]Error. The argument must be a number.");

	return result;
}

void Menu::tokenize(const std::string & str, std::vector<std::string>& tokens, const std::string & delimiters) {



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

			if (tokens[1] == "x")
				mPoint.setX(numberStringCast<double>(tokens[2]));
			else if (tokens[1] == "y")
				mPoint.setY(numberStringCast<double>(tokens[2]));
			else
				throw runtime_error("[!] Error. Can't understand 2nd arg.");
		} else if (tokens[0] == "get") {
			if (tokens.size() != 2) throw runtime_error("[!] Error. get needs 1 args");

			if (tokens[1] == "x")
				cout << "The x coordinate of the Point is " << mPoint.getX();
			else if (tokens[1] == "y")
				cout << "The y coordinate of the Point is " << mPoint.getY();
			else if (tokens[1] == "all")
				cout << "The x, y coordinate of the Point is (" << mPoint.getX() << ", " << mPoint.getY() << ")";
			else
				throw runtime_error("[!] Error. Can't understand 2nd arg.");
		} else if (tokens[0] == "mov") {
			if (tokens.size() != 3) throw runtime_error("[!] Error. move needs 2 args");

			if (tokens[1] == "x")
				mPoint.move(Point::Direction::HORIZONTAL,numberStringCast<double>(tokens[2]));
			else if (tokens[1] == "y")
				mPoint.move(Point::Direction::VERTICAL,numberStringCast<double>(tokens[2]));
			else
				throw runtime_error("[!] Error. Can't understand 2nd arg.");
		} else if (tokens[0] == "rot") {
			if (tokens.size() != 2) throw runtime_error("[!] Error. rot needs 1 args");

			mPoint.rotateClockwise(numberStringCast<double>(tokens[1]));
		}
		else {
			throw runtime_error("[!] Error. Can't understand.");
		}


	} catch (const exception& e) {
		cout << e.what();
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
