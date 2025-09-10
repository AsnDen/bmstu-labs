#include <iostream>

int main()
{
	int arr[10];
	int sm = 0;

	for (int i = 0; i < 10; i++) {
		std::cin >> arr[i];
		sm += arr[i];
	}

	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << "\n" << sm << "\n";

	bool isSorted = false;
	int box;
	while (!isSorted) {
		isSorted = true;
		for (int i = 0; i < 9; i++) {
			if (arr[i] > arr[i + 1]){
				box = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = box;
				isSorted = false;
			}
		}
	}

	std::cout << arr[0] << "\n";

	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}

	return 0;
}