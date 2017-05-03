#pragma once

#include <iostream>
#include <stdexcept>
#include <cmath>

class Money {
public:
	Money();
	Money(double dollarWithCent);
	~Money();

	int getDollar() const;
	void setDollar(int dollar);
	int getCent() const;
	void setCent(int cent);

	Money operator+(Money &ref) { return Money(getDollarWithCent() + ref.getDollarWithCent()); };
	Money operator-(Money &ref) { return Money(getDollarWithCent() - ref.getDollarWithCent()); };
	Money operator*(double factor) { return Money(getDollarWithCent() * factor); };
	friend Money operator*(double factor, const Money& m) { return factor * m; };
	Money operator/(double factor) { return Money(getDollarWithCent() / factor); };
	friend Money operator/(double factor, const Money& m) { return factor / m; };
	bool operator==(Money &ref) { return this->getDollarWithCent() == ref.getDollarWithCent(); };
	Money operator-() const { return Money(-this->getDollarWithCent()); };

	friend std::ostream& operator<<(std::ostream& os, const Money& m) {
		os << m.getDollarWithCent() << " dollars";
		return os;
	}

private:
	int mDollar;
	int mCent;

public:
	void setDollarWithCent(double dollarWithCent);
	double getDollarWithCent() const;
};

