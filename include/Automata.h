#include <iostream>
#include <string.h>
#include <vector>

enum STATES
{
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata
{
private:
	int cash;
	std::vector<std::string> menu = { "Water", "Tea", "Coffee", "Soft drink", "Energy drink", "Juice" };
	std::vector<int> prices = { 10, 30, 50, 75, 130, 60 };
	STATES state;
	std::string stateString(STATES state);
	void check(int option);
	void cancel();
	void cook();
	void finish();
public:
	Automata();
	void on();
	void off();
	void coin(int sum);
	void printMenu();
	void printState();
	void choice(int option);
};
