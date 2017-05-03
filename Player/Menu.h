#pragma once

#include "PlayerList.h"

class Menu {

private:
	PlayerList mPlayerList;
	void tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters = " ");

public:
	Menu(unsigned int maxPlayers) :mPlayerList(maxPlayers) {};
	bool interpret(const std::string& command);
};