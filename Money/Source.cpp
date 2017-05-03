#include <iostream>
#include "Money.h"

using namespace std;

int main() {

	Money myDebt, myMoney, yourMoney, ourMoney;

	cout << "I have 2 dollars and 50 cents." << endl;
	myMoney.setDollar(2); myMoney.setCent(50);

	cout << "I also owe 10.3. dollars => ";
	myDebt.setDollarWithCent(1);
	cout << -myDebt << endl;

	cout << "And you have 5 dollars and 250 cents." << endl << endl;
	yourMoney.setDollar(5); yourMoney.setCent(225);

	cout << "Wait. How much did I say I had?" << endl;
	cout << "Oh I remembered." << endl;
	cout << "It's " << myMoney.getDollar() << " dollars and " << myMoney.getCent() << " cents." << endl << endl;

	cout << "And you have " << yourMoney << " right? " << ((yourMoney == Money(7.25)) ? "yes" : "no") << endl;;

	cout << "If we put all our money together ...!" << endl;
	ourMoney = myMoney + yourMoney;
	cout << myMoney << " + " << yourMoney << " => " << ourMoney << endl;

	cout << "\n\n... After a long time. Our business was a big hit and our money became six times." << endl;
	cout << "So our money is " << ourMoney << " => ";
	ourMoney = ourMoney * 6;
	cout << ourMoney << endl << endl;

	cout << "But we were getting farther away and eventually we decided to break in 1 : 2" << endl;
	myMoney = ourMoney / 3;
	yourMoney = ourMoney - myMoney;
	cout << "Now I have " << myMoney << " And you have " << yourMoney << endl;

	cout << "Is my money the same as your money? " << ((myMoney == yourMoney) ? "yes" :"no") << endl;
	return EXIT_SUCCESS;
}