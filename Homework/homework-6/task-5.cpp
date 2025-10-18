#include <iostream>
#include <cstring>
#include <cctype>

void stringToLower(char str[]) {
    int len {int(strlen(str))};

    for (int i = 0; i < len; i++) str[i] = tolower(str[i]);
}

int main() {

    char str[100];
    std::cin.getline(str, 100);

    stringToLower(str);

    int len {int(strlen(str))};
    int counterVowels {0};
    int counterConsonants {0};
    char vowels[7] {"aeiouy"};
    for (int i = 0; i < len; i++) {
        char temp[2] {str[i], '\0'};
        (isalpha(str[i])) && ((strstr(vowels, temp) && (++counterVowels)) || (++counterConsonants));
    }

    printf("Vowels: %d\nConsonants: %d\n", counterVowels, counterConsonants);
    return 0;
}