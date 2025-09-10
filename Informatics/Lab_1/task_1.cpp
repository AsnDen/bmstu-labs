#include <iostream>

int main()
{
	double income;
	
	std::cout << "Tell your income, please\n";
	std::cin >> income;
	
	if (income <= 50000) {
		std::cout << "Your tax rate is 13%\n";
		std::cout << "Your tax fee is " << income * 0.13;
	} else if (50001 <= income && income <= 100000) {
		std::cout << "Your tax rate is 20%\n";
		std::cout << "Your tax fee is " << income * 0.20;
	} else {
		std::cout << "Your tax rate is 25%\n";
		std::cout << "Your tax fee is " << income * 0.25;
	}

	return 0;
}