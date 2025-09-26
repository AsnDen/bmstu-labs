#include <iostream>
#include <algorithm>

using namespace std;

int findIndex(double num, int len, double arr[]) {

	for (int i = 0; i < len; i++) {
		if (num == arr[i]) {
			return i;
		}
	}

	return -1;
}

double findMax(int len, double arr[]) {
	double max = arr[0];
	for (int i = 1; i < len; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	} 
	return max;
}

double findMin(int len, double arr[]) {
	double min = arr[0];
	for (int i = 1; i < len; i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
	} 
	return min;
}

int main() {
	const int n = 15;
	double arr[n];

	cout << "Input array" << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	double max = findMax(n, arr);
	int maxIndex = findIndex(max, n, arr);

	double min = findMin(n, arr);
	int minIndex = findIndex(min, n, arr);

	if (maxIndex < minIndex) {
		cout << min * max << endl;
	}

	return 0;
}

