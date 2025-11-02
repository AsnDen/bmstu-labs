#include <iostream>

int main() {

    char *str = new char[200];

    std::cin.getline(str, 200);

    char *src = str;

    while (*src != '\0') {
        if (*src == ' ') *src = '_';
        src++;
    }
    
    printf("%s", str);

    return 0;
}