#include "PlayerList.h"

using namespace std;

PlayerList::PlayerList(unsigned int maxPlayers) : MAX_PLAYERS(maxPlayers) {
}


PlayerList::~PlayerList() {
}


double PlayerList::getHighScoreByName(const string& name) {

	auto PlayerSearched = searchByName(name);
	if (PlayerSearched != mPlayers.end()) {
		return PlayerSearched->getHighScore();
	}

	throw out_of_range("[!] Error. There aren't " + name);
}


void PlayerList::deletePlayerByName(const string& name) {
	auto PlayerSearched = searchByName(name);
	if (PlayerSearched != mPlayers.end()) {
		mPlayers.erase(PlayerSearched);
		return;
	}

	throw out_of_range("[!] Error. There aren't " + name);

}

void PlayerList::addPlayer(const string & name, double score) {


	if (mPlayers.size() > 9)
		throw invalid_argument("[!] Error. Player max now");

	if (searchByName(name) != mPlayers.end())
		throw invalid_argument("[!] Error. There are already " + name + " exists..");

	Player newPlayer(name, score);
	mPlayers.push_back(newPlayer);

	sort(mPlayers.begin(), mPlayers.end());
}


void PlayerList::listPlayers() {
	for (auto playerIter = mPlayers.begin(); playerIter != mPlayers.end(); playerIter++)
		cout << playerIter->getName() << "\t(" << playerIter->getHighScore() << ")" << endl;
}


vector<Player>::iterator PlayerList::searchByName(const string& name) {
	int start = 0, end = mPlayers.size(), idx = 0;

	while (start != end && end != 0) {
		idx = (start + end) / 2;
		if (mPlayers[idx].getName() < name)
			start = idx + 1;
		else if (mPlayers[idx].getName() > name)
			end = idx;
		else
			return mPlayers.begin() + idx; // Returns the position found.
	}

	return mPlayers.end(); // If not found, returns end.
}
