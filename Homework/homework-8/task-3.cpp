#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>

void free2D(int **arr, int n) {
    for (int i = 0; i < n; i++) delete[] arr[i];
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

    free2D(arr, rows);
    
    return 0;
}