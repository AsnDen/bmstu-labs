#include <iostream>

using namespace std;

int main() {
	int age;

	cout << "Tell us your age" << endl;
	cin >> age;
	while (age < 0) {
		cout << "Age can't be negative number" << endl;
		cin >> age;
	}
	
	if (age < 18) {
		cout << "You are younger than 18 years old" << endl;
	} else if (age > 60) {
		cout << "You are older than 60 years old" << endl;
	} else {
		cout << "You are betweeen 18 and 60 years old" << endl;
	}
}