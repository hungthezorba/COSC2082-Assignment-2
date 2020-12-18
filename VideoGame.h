#pragma once
#include "Item.h"
#include <string>

class VideoGame : public Item {
	
public:
	VideoGame();
	VideoGame(string id, string title, string rentalType, string loanType, int numberOfCopies, double rentalFee);
	VideoGame(VideoGame &vr);
};