
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

bool validateCustomerName(string input);

bool validateCustomerAddress(string input);

bool validateCustomerPhoneNumber(string input);

bool validateCustomerType(string input);