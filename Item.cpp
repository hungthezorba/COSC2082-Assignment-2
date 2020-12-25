//
// Created by Hung Nguyen on 26/04/19.
//
#include "Item.h"
#include <iostream>
using namespace std;

string Item::getId() const {
	return id;
}

void Item::setId(string id) {
	this -> id = id;
}

string Item::getTitle() const {
	return title;
}

void Item::setTitle(string title) {
	this->title = title;
}

string Item::getRentalType() const {
	return rentalType;
}

void Item::setRentalType(string rentalType) {
	this->rentalType = rentalType;
}

string Item::getLoanType() const {
	return loanType;
}

void Item::setLoanType(string loanType) {
	this->loanType = loanType;
}

int Item::getNumberOfCopies() const {
	return numberOfCopies;
}

void Item::setNumberOfCopies(int numberOfCopies) {
	this->numberOfCopies = numberOfCopies;
	checkStockAndSetRentalStatus();

}

double Item::getRentalFee() const {
	return rentalFee;
}

void Item::setRentalFee(double rentalFee) {
	this->rentalFee = rentalFee;
}

string Item::getRentalStatus() const {
	return rentalStatus;
}

void Item::setRentalStatus(string rentalStatus) {
	this->rentalStatus = rentalStatus;
}

Item::Item() {
	this->id = "";
	this->title = "";
	this->rentalType = "";
	this->loanType = "";
}

Item::Item(string id, string title, string rentalType, string loanType, int numberOfCopies, double rentalFee) {
	this->id = id;
	this->title = title;
	this->rentalType = rentalType;
	this->loanType = loanType;
	this->numberOfCopies = numberOfCopies;
	this->rentalFee = rentalFee;
	this->rentalStatus = "available";
}

Item::Item(Item &i) {
	this->id = i.id;
	this->title = i.title;
	this->rentalType = i.rentalType;
	this->loanType = i.loanType;
	this->numberOfCopies = i.numberOfCopies;
	this->rentalFee = i.rentalFee;
	checkStockAndSetRentalStatus();

}

// return true if can be rented or false if cannot be rented
bool Item::renting() {
	if (numberOfCopies > 0) {
		numberOfCopies--;
		checkStockAndSetRentalStatus();
		return true;
	}
	else {
		return false;
	}
}

bool Item::returning() {
	numberOfCopies++;
	checkStockAndSetRentalStatus();
	return true;
}

bool Item::increaseStock(int num) {
	numberOfCopies += num;
	checkStockAndSetRentalStatus();
	return true;
}

bool Item::checkStockAndSetRentalStatus() {
	if (numberOfCopies > 0) {
		this->setRentalStatus("Available");
		return true;
	}
	else {
		this->setRentalStatus("Borrowed");
		return false;
	}
}

void Item::printDetail() {
		cout << this->id << " - " << this->title << " - " << this->rentalType << " - " << this->loanType << " - " << this->numberOfCopies << " - " << this->rentalFee << " - " << this->rentalStatus <<endl;	
}

string Item::getGenre() {
	return "";
}
void Item::setGenre(string genre) {}