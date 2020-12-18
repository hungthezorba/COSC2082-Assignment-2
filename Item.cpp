//
// Created by Hung Nguyen on 26/04/19.
//

#include "Item.h"

const string &Item::getId() const {
    return id;
}

void Item::setId(const string &id) {
    Item::id = id;
}

const string &Item::getTitle() const {
    return title;
}

void Item::setTitle(const string &title) {
    Item::title = title;
}

const string &Item::getRentalType() const {
    return rentalType;
}

void Item::setRentalType(const string &rentalType) {
    Item::rentalType = rentalType;
}

const string &Item::getLoanType() const {
    return loanType;
}

void Item::setLoanType(const string &loanType) {
    Item::loanType = loanType;
}

int Item::getNumberOfCopies() const {
    return numberOfCopies;
}

void Item::setNumberOfCopies(int numberOfCopies) {
    Item::numberOfCopies = numberOfCopies;
}

double Item::getRentalFee() const {
    return rentalFee;
}

void Item::setRentalFee(double rentalFee) {
    Item::rentalFee = rentalFee;
}

bool Item::isRentalStatus() const {
    return rentalStatus;
}

void Item::setRentalStatus(bool rentalStatus) {
    Item::rentalStatus = rentalStatus;
}

Item::Item() {
    this -> id = "";
    this -> title = "";
    this -> rentalType = "";
    this -> loanType = "";
}

Item::Item(string id, string title, string rentalType, string loanType, int numberOfCopies,double rentalFee) {
    this -> id = id;
    this -> title = title;
    this -> rentalType = rentalType;
    this -> loanType = loanType;
    this -> numberOfCopies = numberOfCopies;
    this -> rentalFee = rentalFee;
}

// return true if can be rented or false if cannot be rented
bool Item::renting() {
    if (numberOfCopies > 0) {
        numberOfCopies--;
        return true;
    } else {
        return false;
    }
}

bool Item::returning() {
    numberOfCopies++;
    return true;
}