#include <iostream>
#include <cstring>

char* stringRemoveChar(char str[], char remover) {
    int len {int(strlen(str))};
    char* newStr {new char[100]};
    int index {0};

    for (int i = 0; i < len; i++) (str[i] != remover) && (newStr[index++] = str[i]);

    newStr[index] = '\0';

    return newStr;
}

int main() {

    char inp[100];
    std::cin.getline(inp, 100);
    char remover;
    std::cin >> remover;
    char* str {stringRemoveChar(inp, remover)};

    printf("%s", str);

    return 0;
}