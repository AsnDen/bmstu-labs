#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> reflectMainDiagonal(std::vector<std::vector<int>> matrix) {
    std::vector<std::vector<int>> newMatrix = matrix;
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            std::swap(newMatrix[i][j], newMatrix[j][i]);
        }
    }

    return newMatrix;

}

bool isRowsSumSame(std::vector<std::vector<int>> matrix) {
    int n = matrix.size();

    std::vector<int> sums;

    for (int i = 0; i < n; i++) {
        int sm = 0;
        for (int j = 0; j < n; j++) {
            sm += matrix[i][j];
        }
        sums.push_back(sm);
    }

    bool areSame = true;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (sums[i] != sums[j]) {
                areSame = false;
                break;
            }
        }
    }

    return areSame;

}

int main() {
    int n;
    std::cout << "How many rows and lines are in the matrix?" << std::endl;
    std::cin >> n;
    
    std::cout << "Fill the matrix" << std::endl;
    std::vector<std::vector<int>> matrix;
    
    matrix.resize(n);

    for (int i = 0; i < n; i++) {
        matrix[i].resize(n);
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }

    if (isRowsSumSame(matrix) && isRowsSumSame(reflectMainDiagonal(matrix))) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}