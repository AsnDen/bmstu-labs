#include <iostream>
#include <cstring>

char* stringRemoveDigits(char str[]) {
    int len {int(strlen(str))};
    char* newStr {new char[100]};
    int index {0};

    for (int i = 0; i < len; i++) (!isdigit(str[i])) && (newStr[index++] = str[i]);

    newStr[index] = '\0';

    return newStr;
}

int main() {

    char inp[100];
    std::cin.getline(inp, 100);

    char* str {stringRemoveDigits(inp)};

    printf("%s", str);

    return 0;
}