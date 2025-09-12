#include <iostream>

void bubbleSorting(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int box = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = box;
			}
		}
	}
}

void showArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
}

void fillArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cin >> arr[i];
	}
}

int findMinInArray(int arr[], int size) {
	int min = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

int findSumOfArray(int arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}

int main()
{
	const int size = 10;
	int nums[size];

	std::cout << "Fill array with integers" << std::endl;
	fillArray(nums, size);

	std::cout<< "Your array is:" << std::endl;
	showArray(nums, size);

	std::cout << std::endl << "Sum of array is: " << findSumOfArray(nums, size) << std::endl;

	std::cout << "Minimum integer in array is " << findMinInArray(nums, size) << std::endl;

	bubbleSorting(nums, size);

	std::cout << "Sorted array is:" << std::endl;
	showArray(nums, size);

	return 0;
}