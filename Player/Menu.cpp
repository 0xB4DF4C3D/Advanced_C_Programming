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
		if (tokens[0] == "add") {
			if (tokens.size() != 3) throw invalid_argument("[!] Error. add needs 2 args");
			mPlayerList.addPlayer(tokens[1], numberStringCast<double>(tokens[2]));

		} else if (tokens[0] == "list") {
			if (tokens.size() != 1) throw invalid_argument("[!] Error. list needs no args");

			mPlayerList.listPlayers();
		} else if (tokens[0] == "del") {
			if (tokens.size() != 2) throw invalid_argument("[!] Error. del needs 2 args");

			mPlayerList.deletePlayerByName(tokens[1]);
		} else if (tokens[0] == "get") {
			if (tokens.size() != 2) throw invalid_argument("[!] Error. del needs 2 args");

			string name = tokens[1];
			double score = mPlayerList.getHighScoreByName(name);
			cout << "The high score of " << name << " is " << score << ".";
		} else {
			throw runtime_error("[!] Error. Can't understand.");
		}


	} catch (const exception& e) {
		cout << e.what();
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
