
#include "ValidateCustomerInput.h"
#include <iostream>

using namespace std;

// All validating functions will return true if input is in correct format, false otherwise

bool validateCustomerID(string input, string mode) {
	if (input[0] != 'C' && input[0] != 'c') { // allow sensitive-case
		if (mode == "input") {
			cout << "ERROR: Item's id must start with 'C'. Please enter again." << endl;
		}
		return false;
	}

	if (input.length() != 4) {
		if (mode == "input") {
			cout << "ERROR: Wrong format. Please enter again." << endl;
		}
		return false;
	}

	for (int i = 1; i < 4; i++) {
		if (!isdigit(input[i])) {
			if (mode == "input") {
				cout << "ERROR: 'xxx' must be a unique code of 3 digits. Please enter again." << endl;
			}
			return false;
		}
	}
	return true;
}

// Validate name. Name cannot contains special characters such as comma, dot, splash, backsplash,...
bool validateCustomerName(string input, string mode) {
	for (int i = 0; i < input.length(); i++) {
		// If characters outside of these range of ascii, it means they are special characters
		if (!( (input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122) || input[i] == 32)) {
			if (mode == "input") {
				cout << "ERROR: Name cannot contains special characters. Please enter again." << endl;
			}
			return false;
		}
	}
	return true;
}

bool validateCustomerAddress(string input, string mode) {

	for (int i = 0; i < input.length(); i++) {
		// Condition is based on ASCII
		if ((input[i] >= 33 && input[i] <= 43) ||
			(input[i] >= 58 && input[i] <= 64) ||
			(input[i] >= 91 && input[i] <= 96) ||
			(input[i] >= 123)) {

			if (mode == "input") {
				cout << "ERROR: Address cannot contains special characters. Please enter again." << endl;
			}

			return false;
		}
	}
	return true;
}

bool validateCustomerPhoneNumber(string input, string mode) {

	// Because the specification did not mention about the format of the phone number like maxium of digit. So we will assume base on database files that it only contains 10 digits.
	if (input.length() != 10) {
		if (mode == "input") {
			cout << "ERROR: Wrong format. Please enter again." << endl;
		}
		return false;
	}

	for (int i = 0; i < 10; i++) {
		if (!isdigit(input[i])) {
			if (mode == "input") {
				cout << "ERROR: Phone number only contains digit. Please enter agian." << endl;
			}
			return false;
		}
	}
	return true;
}

bool validateCustomerNumberOfRental(string input, string mode) {
	// Number of copies must be a string contains digit only
	for (int i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) {
			if (mode == "input") {
				cout << "ERROR: Number of rental only contains digits. Please enter again." << endl;
			}
			return false;
		}
	}
	return true;
}

bool validateCustomerType(string input, string mode) {
	if (input.length() == 0) {
		return false;
	}
	if (input != "Guest" && input != "Regular" && input != "VIP") {
		if (mode == "input") {
			cout << "ERROR: Customer type must be in 'Guest', 'Regular' or 'VIP'. Please enter again." << endl;
		}
		return false;
	}
	return true;
}