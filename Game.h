#pragma once
#include "Item.h"
#include <string>

class Game : public Item {
	
public:
	Game();
	Game(string id, string title, string rentalType, string loanType, int numberOfCopies, double rentalFee);
	Game(Game &g);
	void printDetail();
};