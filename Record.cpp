#include "stdafx.h"
#include "Record.h"
#include <iostream>
using namespace std;

Record::Record(string id, string title, string rentalType, string loanType, int numberOfCopies, double rentalFee, string genre) : Item(id, title, rentalType, loanType, numberOfCopies, rentalFee) {
	this->genre = genre;
}


string Record::getGenre() {
	return genre;
}
void Record::setGenre(string genre) {
	this->genre = genre;
}

void Record::printDetail() {
	cout << this->getId() << " - " << this->getTitle() << " - " << this->getRentalType() << " - " << this->getLoanType() << " - " << this->getNumberOfCopies() << " - " << this->getRentalFee() << " - " << this->getGenre() << " - " << this->getRentalStatus() << endl;
}