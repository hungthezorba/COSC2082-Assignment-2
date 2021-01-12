#include "ValidateItemInput.h"
#include <iostream>
#include <string>

using namespace std;


// Implement validate ID
bool validateItemID(string input,string mode) {
	if (input[0] != 'I') {
	    if (mode == "input"){
            cout << "ERROR: Item's id must start with 'I'. Please enter again." << endl;
	    }
	    else if (mode =="readFile"){
	        cout<<"";
	    }

		return false;
	}

	// Check item's unique code.
	for (int i = 1; i < 4; i++) {
		if (!isdigit(input[i])) {
            if (mode == "input"){
                cout << "ERROR: 'xxx' must be a unique code of 3 digits. Please enter again." << endl;
            }
            else if (mode =="readFile"){
                cout<<"";
            }

			return false;
		}
	}
	
	// Check item's id format
	if (input[4] != '-' || input.length() != 9) {
        if (mode == "input"){
            cout << "ERROR: Wrong format. Please enter again." << endl;
        }
        else if (mode =="readFile"){
            cout<<"";
        }

		return false;
	}
	string year;
	for (int i = 5; i < 9; i++) {
		// Check if 4 chars are digits
		year.push_back(input[i]);
		if (!isdigit(input[i])) {
            if (mode == "input"){
                cout << "ERROR: 'yyyy' must be 4 digits represent the published year. Please enter again." << endl;
            }
            else if (mode =="readFile"){
                cout<<"";
            }

			return false;
		}
	}
	// Check year's sanity 
	if (stoi(year) > 2021 || stoi(year) < 1900) {
        if (mode == "input"){
            cout << "ERROR: 'yyyy' must be between 1900 and 2021. Please enter again." << endl;
        }
        else if (mode =="readFile"){
            cout<<"";
        }

		return false;
	}
	return true;
}

// Implement validate title
bool validateTitle(string input,string mode) {
	// String cannot contain comma because the data is separated by comma in the txt file.
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ',') {
            if (mode == "input"){
                cout << "ERROR: Title cannot contains comma. Please enter again." << endl;
            }
            else if (mode =="readFile"){
                cout<<"";
            }

			return false;
		}
	}
	return true;
}

// Implement validate rental type
bool validateRentalType(string input,string mode) {
	// case-sensitive ?
	// Rental type can only in three categories: Game, DVD, Record
	if (input != "Game" && input != "DVD" && input != "Record") {
        if (mode == "input"){
            cout << "ERROR: Rental type must be in 'Game', 'DVD' or 'Record'. Please enter again." << endl;
        }
        else if (mode =="readFile"){
            cout<<"";
        }

		return false;
	}
	return true;
}

// Implement validate loan type
bool validateLoanType(string input,string mode) {
	// case-sensitive ?
	// Loan type can only in two categories: 2-days and 1-week
	if (input != "2-day" && input != "1-week") {
        if (mode == "input"){
            cout << "ERROR: Rental type must be in 'Game', 'DVD' or 'Record'. Please enter again." << endl;
        }
        else if (mode =="readFile"){
            cout<<"";
        }
		return false;
	}
	return true;
}

// Implement validate number of copies 
bool validateNumberOfCopies(string input,string mode) {
	// Number of copies must be a string contains digit only
	for (int i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) {
            if (mode == "input"){
                cout << "ERROR: Number of copies only contains digits. Please enter again." << endl;
            }
            else if (mode =="readFile"){
                cout<<"";
            }

			return false;
		}
	}
	return true;
}

// Implement validate rental fee
bool validateRentalFee(string input,string mode) {
	int decimal = 0;
	// Check input length. 0 means it is an empty string
	if (input.length() == 0) {
		if (mode == "input") {
			cout << "ERROR: Fee is in wrong format. Please enter again." << endl;
		}
		else if (mode == "readFile") {
			cout << "";
		}
		return false;
	}
	for (int i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) {
			if (input[i] == '.' && decimal < 1) {
				decimal++;
			}
			else {
               
				return false;
			}
		}
	}
	return true;
}

// Implement validate genre
bool validateGenre(string input,string mode) {
	// case-sensitive ?
	// Genre can only in four categories: Horror, Comedy, Drama, Action
	if (input != "Horror" && input != "Comedy" && input != "Drama" && input != "Action") {
        if (mode == "input"){
            cout << "ERROR: Genre must be in 'Horror', 'Comedy', 'Drama' or 'Action'. Please enter again." << endl;
        }
        else if (mode =="readFile"){
            cout<<"";
        }
        return false;
	}
	return true;
}




