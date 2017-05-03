#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Player.h"

class PlayerList {
public:
	PlayerList(unsigned int maxPlayers);
	~PlayerList();

private:
	std::vector<Player> mPlayers;
	const unsigned int MAX_PLAYERS;
	std::vector<Player>::iterator  searchByName(const std::string& name);
public:
	double getHighScoreByName(const std::string& name);
	void deletePlayerByName(const std::string& name);
	void addPlayer(const std::string& name, double score);
	void listPlayers();
};

