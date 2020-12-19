#include "stdafx.h"
#include "DVD.h"
#include <iostream>
using namespace std;

DVD::DVD(string id, string title, string rentalType, string loanType, int numberOfCopies, double rentalFee, string genre) : Item(id, title, rentalType, loanType, numberOfCopies, rentalFee) {
	this->genre = genre;
}


string DVD::getGenre() {
	return genre;
}
void DVD::setGenre(string genre) {
	this->genre = genre;
}

void DVD::printDetail() {
	cout << this->getId() << " - " << this->getTitle() << " - " << this->getRentalType() << " - " << this->getLoanType() << " - " << this->getNumberOfCopies() << " - " << this->getRentalFee() << " - " << this->getGenre() << " - " << this->getRentalStatus() << endl;
}