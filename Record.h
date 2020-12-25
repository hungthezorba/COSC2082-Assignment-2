#pragma once
#include "Item.h"

class Record : public Item {
	private:
		string genre;

	public:
		Record();
		Record(string id, string title, string rentalType, string loanType, int numberOfCopies, double rentalFee, string genre);
		string getGenre();
		void setGenre(string genre);
		void printDetail();
};