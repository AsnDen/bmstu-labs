#include <iostream>

int myStrCmp(const char* s1, const char* s2) {
    while (*s1 == *s2) {
        if (*s1 == '\0') return 0;
        s1++;
        s2++;
    }

    return (*s1 < *s2) ? -1 : 1;
}

int main() {
    
    char *str1 = new char[200];

    std::cin.getline(str1, 200);

    char *str2 = new char[200];

    std::cin.getline(str2, 200);

    std::cout << myStrCmp(str1, str2) << std::endl;
    
    return 0;
}