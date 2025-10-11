#include <iostream>
#include <vector>

double calc2Determ(std::vector<std::vector<int>> matrix) {
    return matrix[0][0]*matrix[1][1] - matrix[1][0]*matrix[0][1];
}

int main() {
    int n = 2;
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> matrixX;
    std::vector<std::vector<int>> matrixY;
    
    matrix.resize(n);

    matrix[0] = {2, 3};
    matrix[1] = {5, -1};

    matrixX = matrix;
    matrixX[0][0] = 13;
    matrixX[1][0] = 9;

    matrixY = matrix;
    matrixY[0][1] = 13;
    matrixY[1][1] = 9;

    std::cout << calc2Determ(matrixX) << " " << calc2Determ(matrix) << " " << calc2Determ(matrixY) << std::endl;

    std::cout << "X is " << calc2Determ(matrixX)/calc2Determ(matrix) << std::endl;
    std::cout << "Y is " << calc2Determ(matrixY)/calc2Determ(matrix) << std::endl;

    return 0;
}