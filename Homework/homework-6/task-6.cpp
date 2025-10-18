#include <iostream>
#include <cstring>

char* Caesar(char str[], int shift) {
    char* caesar {new char[100]};
    int len {int(strlen(str))};
    char base {'a'};
    for (int i = 0; i < len; i++){
        (isalpha(str[i])) && (((tolower(str[i]) == str[i]) && (base = 'a')) || (base = 'A'));
        ((isalpha(str[i])) && (caesar[i] = ((str[i] - base + shift) % 26 + base))) || (caesar[i] = str[i]);
    }

    caesar[len] = '\0';

    return caesar;
}

int main() {

    char str[100];
    std::cin.getline(str, 100);
    int shift;
    std::cin >> shift;

    char* casear = Caesar(str, shift);

    printf("%s", casear);
}