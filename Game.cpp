#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() : Item() {

}

Game::Game(string id, string title, string rentalType, string loanType, int numberOfCopies, double rentalFee) : Item(id, title, rentalType, loanType, numberOfCopies, rentalFee) {

}



void Game::printDetail() {

	cout << this->getId() << " - " << this->getTitle() << " - " << this->getRentalType() << " - " << this->getLoanType() << " - " << this->getNumberOfCopies() << " - " << this->getRentalFee() << " - " << this->getRentalStatus() << endl;
}