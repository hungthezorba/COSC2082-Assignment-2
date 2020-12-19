#pragma once
#include "Item.h"

class DVD : public Item {
private:
	string genre;

public:
	DVD();
	DVD(string id, string title, string rentalType, string loanType, int numberOfCopies, double rentalFee, string genre);
	string getGenre();
	void setGenre(string genre);
	void printDetail();
};