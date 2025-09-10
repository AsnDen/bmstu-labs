#include <iostream>

int main()
{
	std::cout << "Amount\tPrice\n";
	for (int i = 1; i <= 10; i++) {
		std::cout << i << "\t" << i * 10 << "\n";
	}

	return 0;
}