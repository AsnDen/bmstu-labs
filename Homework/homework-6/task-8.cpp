#include <iostream>
#include <cstring>

int main() {

    char str[100];
    std::cin.getline(str, 100);

    int len {int(strlen(str))};
    char symb[] {".!?"};
    bool isSentence {true};
    for (int i = 0; i < len; i++) {
        char temp[2] {str[i], '\0'};
        ((isSentence) && (isalpha(str[i])) && (isSentence = false, str[i] = toupper(str[i]))) || (str[i] = tolower(str[i]));
        (strstr(symb, temp)) && (isSentence = true);
    }

    printf("%s", str);
}