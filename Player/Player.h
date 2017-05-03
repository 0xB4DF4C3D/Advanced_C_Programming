#pragma once

#include <stdexcept>
#include <string>

class Player {
public:
	Player(const std::string& name, double score);
	~Player();

	std::string getName() const;
	void setName(const std::string& name);

	double getHighScore() const;
	void setHighScore(double score);

	bool operator<(const Player& ref) const {
		return this->mName < ref.mName;
	}

private:
	std::string mName;
	double mHighScore;
};

