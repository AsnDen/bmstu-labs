#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>
#include <algorithm>


void free2D(int **arr, int n) {
    for (int i = 0; i < n; i++) delete[] arr[i];
}

int rowSum(int* row, int colums) {
    int s{};
    for (int i{}; i < colums; i++) s += row[i];
    return s;
}

void sortBySum(int **arr, int rows, int colums) {
    for (int i = 0; i < rows-1; i++) for (int j = 0; j < rows-i-1; j++) {
        int s1 = rowSum(arr[j], colums);
        int s2 = rowSum(arr[j + 1], colums);

        if (s1 > s2) std::swap (arr[j], arr[j+1]);
    }
}

int main() {
    
    srand(time(0));
    int rows, colums;

    std::cin >> colums >> rows;
    
    int** arr = new int*[rows];

    for (int i = 0; i < rows; i++) arr[i] = new int[colums];

    std::cout << std::left;

    for (int i = 0; i < rows; i++)  {
        for (int j = 0; j < colums; j++) {
            arr[i][j] = rand() % 100;
            std::cout << std::setw(3) << arr[i][j];
        }
        std::cout << std::endl;
    }

    sortBySum(arr, rows, colums);

    std::cout << "---------------" << std::endl;

    for (int i = 0; i < rows; i++)  {
        for (int j = 0; j < colums; j++) {
            std::cout << std::setw(3) << arr[i][j];
        }
        std::cout << std::endl;
    }

    free2D(arr, rows);
    
    return 0;
}