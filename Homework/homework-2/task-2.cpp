#include <iostream>

using namespace std;

double static input_validator(double inp) {
	while (inp <= 0) {
		cout << "Incorrect input. Use number that is positive" << endl;
		cin >> inp;
	}
	return inp;
}

int main() {
	cout << "This is calculator of rectangle area" << endl;
	double width, length;
	cout << "Input the width" << endl;
	cin >> width;
	width = input_validator(width);
	cout << "Input the length" << endl;
	cin >> length;
	length = input_validator(length);
	cout << "The area is " << width * length;
}