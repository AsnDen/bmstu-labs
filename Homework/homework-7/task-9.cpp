#include <iostream>

int main() {

    char *str = new char[200];

    std::cin.getline(str, 200);

    char *src = str;
    char *p = str;

    while (*src != '\0') {
        if (*src != ' ') {
            *p = *src;
            p++;
        }
        src++;
    }
    
    printf("%s", str);

    return 0;
}