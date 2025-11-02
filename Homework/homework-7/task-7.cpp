#include <iostream>

bool isPalindrome(const char* str) {

    const char *start = str;
    const char *end = str;

    while (*end != '\0') end++;
    end--;

    char temp;
    while (start < end) {
        if (*start != *end) return false;
        start++;
        end--;
    }

    return true;

}

int main() {

    char *str = new char[200];

    std::cin.getline(str, 200);

    isPalindrome(str) ? printf("It is palindrome") : printf("It isn't palindrome");

    return 0;
}