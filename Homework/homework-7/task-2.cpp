#include <print>

int myStrLen(const char* str) {
    int counter {0};
    while (*(str+counter) != '\0') {
        counter++;
    }
    return counter;
}

void myStrCopy(char* dest, const char* str) {
    while (*str != '\0') {
        *dest = *str;
        dest++;
        str++;
    }
    *dest = '\0';
}


int main() {

    char str[] {"Haha stupid string"};

    char *newStr = new char[myStrLen(str)+1];

    myStrCopy(newStr, str);

    printf("%s", newStr);

    return 0;
}