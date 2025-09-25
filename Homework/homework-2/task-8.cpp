#include <iostream>
#include <string>

using namespace std;

int countChars(string chars, char ch) {
	if (chars.empty()) {
		return 0;
	}
	

	int counter = 0;
	int i = 0;
	string checkedChars = "";
	
	while (checkedChars != chars) {
		if (chars[i] == ch) {
			counter++;
		}
		checkedChars += chars[i];
		i++;
	}

	return counter;
}

int main() {
	string inp;
	cout << "Waiting for string" << endl;
	cin >> inp;

	int sm = countChars(inp, 'a') + countChars(inp, 'e') + countChars(inp, 'i') + countChars(inp, 'o') + countChars(inp, 'u') + countChars(inp, 'y');
	cout << "There are " << sm << " vowels" << endl;

	return 0;
}