#include <iostream>
#include <cstring>

void stringToLower(char str[]) {
    int len {int(strlen(str))};

    for (int i = 0; i < len; i++) str[i] = tolower(str[i]);
}

int main() {

    char str[100];
    std::cin.getline(str, 100);
    stringToLower(str);

    int len {int(strlen(str))};
    int counter {1};
    for (int i = 1; i < len; i++) {
        bool isAny {false};
        for (int j = 0; j < i; j++) (str[i] == str[j]) && (isAny = true);
        if (!isAny) counter++;
    }

    printf("%d", counter);

    return 0;
}