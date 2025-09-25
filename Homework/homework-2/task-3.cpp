#include <iostream>

using namespace std;

double static celsius_validator(double inp) {
	while (inp < -273) {
		cout << "Incorrect input. Celsius degrees must be greater or equal to -273" << endl;
		cin >> inp;
	}
	return inp;
}

double static celsius_to_farennheit(double celsius) {
	return celsius * 9 / 5 + 32;
}

int main() {
	cout << "This is calculator of farennheit degrees" << endl;
	double celsius;
	cout << "Input the celsius degrees" << endl;
	cin >> celsius;
	celsius = celsius_validator(celsius);
	cout << "The farennheit degrees are " << celsius_to_farennheit(celsius);
}