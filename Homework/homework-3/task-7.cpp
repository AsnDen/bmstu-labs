#include <iostream>
#include <functional>

using namespace std;

int findIndex(int num, int len, int arr[]) {

	for (int i = 0; i < len; i++) {
		if (num == arr[i]) {
			return i;
		}
	}

	return -1;
}

int findMax(int len, int arr[]) {
	int max = arr[0];
	for (int i = 1; i < len; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	} 
	return max;
}

int findMin(int len, int arr[]) {
	int min = arr[0];
	for (int i = 1; i < len; i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
	} 
	return min;
}

void replacer(int index, int num, int len, int arr[]) {
	for (int i = 0; i < index; i++) {
		arr[i] = num;
	}
}

void showArray(int len, int arr[]) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	const int n = 15;
	int arr[n];

	cout << "Input array" << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	showArray(n, arr);

	int max = findMax(n, arr);
	int maxIndex = findIndex(max, n, arr);

	int min = findMin(n, arr);
	int minIndex = findIndex(min, n, arr);

	cout << "Modified array" << endl;
	if ((max == 0) || (min == 0)) {
		replacer(minIndex, 0, n, arr);
		
	}

	showArray(n, arr);

	return 0;
}