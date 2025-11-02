#include <iostream>

void reverse(char* str) {

    char *start = str;
    char *end = str;

    while (*end != '\0') end++;
    end--;

    char temp;
    while (start < end) {
        
        temp = *end;
        *end = *start;
        *start = temp;
        start++;
        end--;
    }

}

int main() {

    char *str = new char[200];

    std::cin.getline(str, 200);

    reverse(str);

    printf("%s", str);

    return 0;
}