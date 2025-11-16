#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <cstring>

void free2D(char **arr, int n) {
    for (int i = 0; i < n; i++) delete[] arr[i];
}

void sortWords(char **words, int count) {
    for (int i = 0; i < count - 1; i++) for (int j = 0; j < count - 1 - i; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) std::swap(words[j], words[j+1]);
    }
}

int main() {
    
    int rows{};
    std::cin >> rows;
    int wordLen {100};

    char** words = new char*[rows];

    for (int i = 0; i < rows; i++) words[i] = new char[wordLen];
    
    for (int i = 0; i < rows; i++)  {
        char temp[100];
        std::cin >> temp;
        std::strcpy(words[i], temp);
    }

    for (int i = 0; i < rows; i++) std::cout << words[i] << std::endl;

    std::cout << "---------------------" << std::endl;

    sortWords(words, rows);

    for (int i = 0; i < rows; i++) std::cout << words[i] << std::endl;

    free2D(words, rows);
    
    return 0;
}