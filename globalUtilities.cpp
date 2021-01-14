#include "globalUtilities.h"
#include <iostream>
#include <string>

using namespace std;

string toLowerCase(string input) {
	for (int i = 0; i < input.length(); i++)
	{
		if (input.at(i) >= 'A' && input.at(i) <= 'Z')
			input.at(i) += 32;
	}
	return input;
}