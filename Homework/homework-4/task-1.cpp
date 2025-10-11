#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

void showMatrix(const std::vector<std::vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[i].size(); j++) {
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

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

std::vector<std::vector<int>> reflectSideDiagonal(std::vector<std::vector<int>> matrix) {
    std::vector<std::vector<int>> newMatrix = matrix;
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        for (int j = n-1-i; j >= 0; j--) {
            if (i + j + 1 == n) {
                continue;
            }
            std::swap(newMatrix[i][j], newMatrix[n-j-1][n-i-1]);
        }
    }
    return newMatrix;
}

std::vector<std::vector<int>> reflectVerticalAxis(std::vector<std::vector<int>> matrix) {
    std::vector<std::vector<int>> newMatrix = matrix;
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n/2; j++) {
            std::swap(newMatrix[i][j], newMatrix[i][n-j-1]);
        }
    }
    return newMatrix;

}


std::vector<std::vector<int>> reflectHorizontalAxis(std::vector<std::vector<int>> matrix) {
    std::vector<std::vector<int>> newMatrix = matrix;
    int n = matrix.size();

    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n; j++) {
            std::swap(newMatrix[i][j], newMatrix[n-i-1][j]);
        }
    }
    return newMatrix;

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
    
    std::vector<std::vector<int>> matrixMainDiag = reflectMainDiagonal(matrix);
    std::vector<std::vector<int>> matrixSideDiag = reflectSideDiagonal(matrix);
    std::vector<std::vector<int>> matrixVertAxis = reflectVerticalAxis(matrix);
    std::vector<std::vector<int>> matrixHorizAxis = reflectHorizontalAxis(matrix);

    std::vector<std::vector<int>> arr[] = {matrixMainDiag, matrixSideDiag, matrixVertAxis, matrixHorizAxis};

    std::cout << "This is your matrix" << std::endl;
    showMatrix(matrix);

    std::cout << "Matrix that is reflected by main diagonal" << std::endl;
    showMatrix(matrixMainDiag);

    std::cout << "Matrix that is reflected by side diagonal" << std::endl;
    showMatrix(matrixSideDiag);

    std::cout << "Matrix that is reflected by vertical axis" << std::endl;
    showMatrix(matrixVertAxis);
    
    std::cout << "Matrix that is reflected by horizontal axis" << std::endl;
    showMatrix(matrixHorizAxis);

    bool areSame = false;
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 4; j++) {
            if (arr[i] == arr[j]) {
                std::cout << "Matrixes " << i+1 << "vand " << j+1 << " are the same" << std::endl;
                areSame = true;
            }
        }
    }

    if (!areSame) {
        std::cout<< "NONE";
    }

    return 0;
}