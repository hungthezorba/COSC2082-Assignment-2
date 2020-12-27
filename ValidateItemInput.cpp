#include "ValidateItemInput.h"
#include <iostream>
#include <string>

using namespace std;


// Implement validate ID
bool validateItemID(string input) {
	if (input[0] != 'I') {
		cout << "ERROR: Item's id must start with 'I'. Please enter again." << endl;
		return false;
	}

	// Check item's unique code.
	for (int i = 1; i < 4; i++) {
		if (!isdigit(input[i])) {
			cout << "ERROR: 'xxx' must be a unique code of 3 digits. Please enter again." << endl;
			return false;
		}
	}
	
	// Check item's id format
	if (input[4] != '-' || input.length() != 9) {
		cout << "ERROR: Wrong format. Please enter again" << endl;
		return false;
	}
	string year;
	for (int i = 5; i < 9; i++) {
		// Check if 4 chars are digits
		year.push_back(input[i]);
		if (!isdigit(input[i])) {
			cout << "ERROR: 'yyyy' must be 4 digits represent the published year. Please enter again." << endl;
			return false;
		}
	}
	// Check year's sanity 
	if (stoi(year) > 2021 || stoi(year) < 1900) {
		cout << "ERROR: 'yyyy' must be between 1900 and 2021. Please enter again." << endl;
		return false;
	}
	return true;
}

// Implement validate title
bool validateTitle(string input) {
	// String cannot contain comma because the data is separated by comma in the txt file.
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ',') {
			cout << "ERROR: Title cannot contains comma. Please enter again." << endl;
			return false;
		}
	}
	return true;
}

// Implement validate rental type
bool validateRentalType(string input) {
	// case-sensitive ?
	// Rental type can only in three categories: Game, DVD, Record
	if (input != "Game" && input != "DVD" && input != "Record") {
		cout << "ERROR: Rental type must be in Game, DVD or Record. Please enter again." << endl;
		return false;
	}
	return true;
}

// Implement validate loan type
bool validateLoanType(string input) {
	// case-sensitive ?
	// Loan type can only in two categories: 2-days and 1-week
	if (input != "2-days" && input != "1-week") {
		cout << "ERROR: Loan type must be 2-days or 1-week. Please enter again." << endl;
		return false;
	}
	return true;
}

// Implement validate number of copies 
bool validateNumberOfCopies(string input) {
	// Number of copies must be a string contains digit only
	for (int i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) {
			cout << "ERROR: Number of copies only contains digits. Please enter again." << endl;
			return false;
		}
	}
	return true;
}

// Implement validate rental fee
bool validateRentalFee(string input) {
	int decimal = 0;
	for (int i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) {
			if (input[i] == '.' && decimal < 1) {
				decimal++;
			}
			else {
				cout << "ERROR: Fee is in wrong format. Please enter again." << endl;
				return false;
			}
		}
	}
	return true;
}

// Implement validate genre
bool validateGenre(string input) {
	// case-sensitive ?
	// Genre can only in four categories: Horror, Comedy, Drama, Action
	if (input != "Horror" && input != "Comedy" && input != "Drama" && input != "Action") {
		cout << "ERROR: Genre must be in Horror, Comedy, Drama or Action. Please enter again." << endl;
		return false;
	}
	return true;
}




