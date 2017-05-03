#include <iostream>
#include <string>

#include "Menu.h"

using namespace std;

int main() {
	Menu myMenu;
	string command;

	cout << "This is a program for testing Weight class.." << endl;

	do {
		cout << ">> ";
		getline(cin, command, '\n');
		if (myMenu.interpret(command))
			cout << "\t...Invalid command" << endl;
		else
			cout << "\t...OK" << endl;

	} while (true);

	return EXIT_SUCCESS;
}