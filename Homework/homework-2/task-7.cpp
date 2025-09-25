#include <iostream>

using namespace std;

int main() {
	int num;

	cout << "Tell how many lines do you want" << endl;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		cout << i << "\t" << i*i << endl;
	}
}