#pragma once
//
// Created by Hung Nguyen on 26/04/19.
//

#include "string"

using namespace std;

class Item {
private:
	string id;
	string title;
	string rentalType;
	string loanType;
	int numberOfCopies;
	double rentalFee;
	string rentalStatus;
public:
	string getId() const;

	void setId(const string id);

	string getTitle() const;

	void setTitle(const string title);

	string getRentalType() const;

	void setRentalType(const string rentalType);

	string getLoanType() const;

	void setLoanType(const string loanType);

	int getNumberOfCopies() const;

	void setNumberOfCopies(int numberOfCopies);

	double getRentalFee() const;

	void setRentalFee(double rentalFee);

	string getRentalStatus() const;

	void setRentalStatus(string rentalStatus);

	Item();

	Item(string id, string title, string rentalType, string loanType, int numberOfCopies, double rentalFee);

	Item(Item &i);

	bool renting();

	bool returning();

	bool increaseStock(int num);

	bool checkStockAndSetRentalStatus();
	//Function to check numberOfCopies and set its availibility

	virtual void printDetail();
	virtual string getGenre();
	virtual void setGenre(string genre);
};
