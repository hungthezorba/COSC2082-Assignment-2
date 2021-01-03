
#include "ValidateCustomerInput.h"
#include <iostream>

using namespace std;


bool validateCustomerID(string input) {
	if (input[0] != 'C') {
		cout << "ERROR: Item's id must start with 'C'. Please enter again." << endl;
		return false;
	}

	if (input.length() != 4) {
		cout << "ERROR: Wrong format. Please enter again." << endl;
		return false;
	}

	for (int i = 1; i < 4; i++) {
		if (!isdigit(input[i])) {
			cout << "ERROR: 'xxx' must be a unique code of 3 digits. Please enter again." << endl;
			return false;
		}
	}
	return true;
}

// Validate name. Name cannot contains special characters such as comma, dot, splash, backsplash,...
bool validateCustomerName(string input) {
	for (int i = 0; i < input.length(); i++) {
		// If characters outside of these range of ascii, it means they are special characters
		if (!( (input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122) || input[i] == 32)) {
			cout << "ERROR: Name cannot contains special characters. Please enter again." << endl;
			return false;
		}
	}
	return true;
}

bool validateCustomerAddress(string input) {

	for (int i = 0; i < input.length(); i++) {
		if ((input[i] >= 33 && input[i] <= 43) ||
			(input[i] >= 58 && input[i] <= 64) ||
			(input[i] >= 91 && input[i] <= 96) ||
			(input[i] >= 123)) {
			cout << "ERROR: Address cannot contains special characters. Please enter again." << endl;
			return false;
		}
	}
	return true;
}

bool validateCustomerPhoneNumber(string input) {

	if (input.length() != 10) {
		cout << "ERROR: Wrong format. Please enter again." << endl;
		return false;
	}

	for (int i = 0; i < 10; i++) {
		if (!isdigit(input[i])) {
			cout << "ERROR: Phone number only contains digit. Please enter agian." << endl;
			return false;
		}
	}
	return true;
}

bool validateCustomerType(string input);