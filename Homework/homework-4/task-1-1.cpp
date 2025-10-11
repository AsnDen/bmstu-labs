#include <iostream>
#include <vector>
#include <cmath>

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
    
    matrix.resize(n);

    std::cout << "Input dot coordinates" << std::endl;

    for (int i = 0; i < n; i++) {
        matrix[i].resize(n);
        for (int j = 0; j < n-1; j++) {
            std::cin >> matrix[i][j];
        }
        matrix[i][2] = 1;
    }

    std::cout << "The area of triangle is " << 0.5*abs(calc3Determ(matrix)) << std::endl;

    return 0;
}