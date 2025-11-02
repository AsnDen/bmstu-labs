#include <iostream>

int main() {

    char *str = new char[200];

    std::cin.getline(str, 200);

    bool newCommand = true;
    bool newValue = false;
    while (*str != '\0') {
        if (newCommand) {
            if (*str == 'T') std::cout << "Temperature: ";
            if (*str == 'P') std::cout << "Pressure: ";
            if (*str == 'H') std::cout << "Humidity: ";
            newCommand = false;
        }
        
        if (*str == ';') newCommand = true, newValue = false, std::cout << std::endl;
        
        if (newValue) {
            std::cout << *str;
        }
        
        if (*str == ':') newValue = true;
        
        str++;
    }

    
    printf("%s", str);

    return 0;
}