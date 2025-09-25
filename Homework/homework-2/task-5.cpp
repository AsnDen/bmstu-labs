#include <iostream>
#include <string>

using namespace std;

int main() {
	int num;
	string answer_start = "The nubmer is divided by ";
	string answer_end = "";
	string answer;

	cout << "This program tell if number can be divided by 3 or 5" << endl;
	
	cout << "Input an integer" << endl;
	cin >> num;
	
	if (num % 3 == 0) {
		answer_end += "3 ";
	}

	if (num % 5 == 0) {
		answer_end += "5";
	}

	if (answer_end == "3 5") {
		answer_end.assign("both 3 and 5");
	}
	else if (answer_end.empty()) {
		answer_end.assign("neither 3 nor 5");
	}

	answer = answer_start + answer_end;

	cout << answer;
}