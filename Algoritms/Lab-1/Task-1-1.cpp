#include <iostream>

int main()
{
	int arr[10];
	int sm = 0;

	// Filling the array and calculating the sum of nums.
	for (int i = 0; i < 10; i++) {
		std::cin >> arr[i];
		sm += arr[i];
	}
	
	// Showing the array
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}

	// Showing the sum
	std::cout << "\n" << sm << "\n";

	// Sorting
	bool isSorted = false;
	int box;
	while (!isSorted) {
		isSorted = true;
		for (int i = 0; i < 9; i++) {
			if (arr[i] > arr[i + 1]){
				box = arr[i]; // Use another value to swap nums in array
				arr[i] = arr[i + 1];
				arr[i + 1] = box;
				isSorted = false;
			}
		}
	}

	// Showing the minimum num in array
	std::cout << arr[0] << "\n";

	// Showing the sorted array
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << " ";
	}

	return 0;
}