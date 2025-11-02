#include <print>

void myStrCat(char* dest, const char* src) {

    while (*dest != '\0') dest++;

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
}


int main() {

    char newStr[] {"Haha stupid"};

    char str[] {" string"};

    myStrCat(newStr, str);

    printf("%s", newStr);

    return 0;
}