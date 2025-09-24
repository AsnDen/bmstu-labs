#include <iostream>
#include <string>
#include <cctype>
#include <locale>

using namespace std;

static bool isStringDigit(string chars) {
	
	if (chars.empty()) {
		return false;
	}
	
	string checked_chars = "";
	int i = 0;
	while (chars != checked_chars) {
		if (!isdigit(chars[i]) && chars[0] != '-') {
			return false;
		}
		
		checked_chars += chars[i];
		i += 1;
	}

	return true;
}

static string pluralForm(int quantity, string noun) {
	if (quantity == 1) {
		return noun;
	}
	return noun + "s";
}

int main() {
	int length = -1;
	string inp;

	setlocale(LC_ALL, "");

	// Input validation
	do {
		cout << "Use integer that is not negative." << endl;
		cin >> inp;
		if (isStringDigit(inp)) {
			length = stoi(inp);
		}
	} while (length < 0);

	string message = "There are ";
	int meters = length / 100;
	int centimeters = length % 100;

	// Add meter or centimeter parts if there are any
	if (meters) {
		message += to_string(meters) + " " + pluralForm(meters, "meter") + " ";
	}

	if (centimeters) {
		message += to_string(centimeters) + " " + pluralForm(centimeters, "centimeter") + " ";
	}

	// If there is 0, then there is nothing
	if (message == "There are ") {
		message += "nothing";
	}
	cout << message;
}