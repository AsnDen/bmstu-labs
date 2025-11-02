#include <iostream>

int main() {

    char *str = new char[200];
    char fChar;

    std::cin.getline(str, 200);
    std::cin >> fChar;

    int counter {0};

    while (*str != '\0') {
        if (*str == fChar) counter++;
        str++;
    }
    
    std::cout << counter << std::endl;

    return 0;
}