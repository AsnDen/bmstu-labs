#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;
	int sm = 0;
	
	for (int i = 1; i <= n; i++) {
		if ((i % 2 == 0) || (i % 5 == 0)) {
			sm += i;
		}
	}

	cout << sm;
	return 0;
}