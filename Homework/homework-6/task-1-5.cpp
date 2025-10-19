#include <iostream>
#include <cstring>
#include <algorithm>

int main() {

    char str[100];
    std::cin.getline(str, 100);
    
    int len {int(strlen(str))};
    
    char* p = strtok(str, " ");
    while (p != nullptr) {
        printf("%s\n", p);
        p = strtok(nullptr, " ");
    }

    return 0;
}