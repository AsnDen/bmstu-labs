#include <print>

int myStrLen(const char* str) {
    int counter {0};
    while (*(str+counter) != '\0') {
        counter++;
    }

    return counter;
}


int main() {

    char str[] {"Haha stupid string"};

    printf("%d", myStrLen(str));

    return 0;
}