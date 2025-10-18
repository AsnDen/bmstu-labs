#include <iostream>
#include <cstring>

int main() {

    char str[100];
    std::cin.getline(str, 100);

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