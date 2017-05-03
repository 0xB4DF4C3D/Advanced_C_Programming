#include "Player.h"

using namespace std;

Player::Player(const std::string& name, double score) {
	setName(name);
	setHighScore(score);
}


Player::~Player() {
}


string Player::getName() const {
	return mName;
}


double Player::getHighScore() const {
	return mHighScore;
}


void Player::setName(const string& name) {
	unsigned int nameLength = name.size();
	if (nameLength < 1 || nameLength > 32)
		throw invalid_argument("name length must be in 1 ~ 32");

	mName = name;
}


void Player::setHighScore(double score) {
	if (score < 0 || score > 100)
		throw invalid_argument("score must be in 0 ~ 100");

	mHighScore = score;
}
