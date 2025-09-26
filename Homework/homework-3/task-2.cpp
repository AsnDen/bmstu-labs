#include <iostream>

using namespace std;

int countEven(int len, int arr[]) {
	int counter = 0;
	for (int i = 0; i < len; i++) {
		if (arr[i] % 2 == 0) {
			counter++;
		}
	}
	return counter;
}

int maxOdd(int len, int arr[]) {
	int max = arr[0];
	for (int i = 1; i < len; i++) {
		if ((arr[i] % 2 == 1) && (max < arr[i])) {
			max = arr[i];
		}
	}

	// In case there are no odd ints
	if (max % 2 == 1){
		return max;
	}
	
	return 0;
}

int main() {
	int n;
	cin >> n;
	int* arr = new int();
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	cout << "Max odd is " << maxOdd(n, arr) << endl;
	cout << "Number of even is  " << countEven(n, arr) << endl;
}

