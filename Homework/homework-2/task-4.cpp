#include <iostream>

using namespace std;

int main() {
	cout << "This program shows if an integer is ever or odd" << endl;
	int num;
	cout << "Input an integer" << endl;
	cin >> num;
	if (num % 2 == 0) {
		cout << "Number is odd" << endl;
	}
	else {
		cout << "Number is even" << endl;
	}
}