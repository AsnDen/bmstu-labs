#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;
	
	if (n > 0) {
		cout << "Number is positive" << endl;
	} else if (n == 0) {
		cout << "Number is zero" << endl;
	} else {
		cout << "Number is negative" << endl;
	}
	return 0;
}