#include "VideoGame.h"

VideoGame::VideoGame() : Item() {

}

VideoGame::VideoGame(string id, string title, string rentalType, string loanType, int numberOfCopies, double rentalFee) : Item(id, title, rentalType, loanType, numberOfCopies, rentalFee) {

}



