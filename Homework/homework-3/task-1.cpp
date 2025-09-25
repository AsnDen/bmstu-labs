#include <iostream>
#include <math.h>

using namespace std;

static int solution(int len, int arr[]) {

	int counter = 0;

	for (int i = 0; i < len; i++) {
		if (arr[i] > pow(2, i+1)) {
			counter++;
		}
	}
	return counter;
}

int main() {
	int n;
	cin >> n;
	int* arr = new int();
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << solution(n, arr);
}

