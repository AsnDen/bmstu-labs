#include <iostream>
#include <vector>

double calc3Determ(std::vector<std::vector<int>> matrix) {
    return matrix[0][0]*matrix[1][1]*matrix[2][2] +
           matrix[0][1]*matrix[1][2]*matrix[2][0] +
           matrix[0][2]*matrix[1][0]*matrix[2][1] -
           matrix[0][2]*matrix[1][1]*matrix[2][0] -
           matrix[0][0]*matrix[1][2]*matrix[2][1] -
           matrix[0][1]*matrix[1][0]*matrix[2][2];
}

int main() {
    int n = 3;
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> matrixX;
    std::vector<std::vector<int>> matrixY;
    std::vector<std::vector<int>> matrixZ;
    
    matrix.resize(n);

    matrix[0] = {3, -1, 2};
    matrix[1] = {2, 4, -1};
    matrix[2] = {1, -3, 1};

    matrixX = matrix;
    matrixX[0][0] = 5;
    matrixX[1][0] = 6;
    matrixX[2][0] = 4;

    matrixY = matrix;
    matrixY[0][1] = 5;
    matrixY[1][1] = 6;
    matrixY[2][1] = 4;


    matrixZ = matrix;
    matrixZ[0][2] = 5;
    matrixZ[1][2] = 6;
    matrixZ[2][2] = 4;

    std::cout << "X is " << calc3Determ(matrixX)/calc3Determ(matrix) << std::endl;
    std::cout << "Y is " << calc3Determ(matrixY)/calc3Determ(matrix) << std::endl;
    std::cout << "Z is " << calc3Determ(matrixZ)/calc3Determ(matrix) << std::endl;

    return 0;
}