#pragma once
//
// Created by Hung Nguyen on 26/04/19.
//

#ifndef COSC2082_ASSIGNMENT_2_ITEM_H
#define COSC2082_ASSIGNMENT_2_ITEM_H
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
	bool rentalStatus;
	string genre;
	string getGenre();
	void setGenre(string genre);
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

	bool isRentalStatus() const;

	void setRentalStatus(bool rentalStatus);

	Item();
	Item(string id, string title, string rentalType, string loanType, int numberOfCopies, double rentalFee, string genre);

	// Overloaded function for Video Game type
	Item(string id, string title, string rentalType, string loanType, int numberOfCopies, double rentalFee);
	Item(Item &i);
	bool renting();
	bool returning();
	virtual void printDetail();
};


#endif //COSC2082_ASSIGNMENT_2_ITEM_H
