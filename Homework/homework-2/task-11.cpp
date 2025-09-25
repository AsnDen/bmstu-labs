#include <iostream>

using namespace std;

int main() {
	for (char i = 32; i <= 126; i++) {
		cout << int(i) << "\t" << i << endl;
	}
}