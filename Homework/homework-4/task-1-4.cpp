#include <iostream>
#include <vector>
#include <cmath>
#include <print>

double calc3Determ(std::vector<std::vector<int>> matrix) {
    return matrix[0][0]*matrix[1][1]*matrix[2][2] +
           matrix[0][1]*matrix[1][2]*matrix[2][0] +
           matrix[0][2]*matrix[1][0]*matrix[2][1] -
           matrix[0][2]*matrix[1][1]*matrix[2][0] -
           matrix[0][0]*matrix[1][2]*matrix[2][1] -
           matrix[0][1]*matrix[1][0]*matrix[2][2];
}

double calc4Determ(std::vector<std::vector<int>> matrix) {
    double det = 0;
    for (int col = 0; col < 4; col++) {
        std::vector<std::vector<int>> minor(3, std::vector<int>(3));
        for (int i = 1; i < 4; i++) {
            int j2 = 0;
            for (int j = 0; j < 4; j++) {
                if (j == col) continue;
                minor[i - 1][j2] = matrix[i][j];
                j2++;
            }
        }
        double sign = (col % 2 == 0) ? 1 : -1;
        det += sign * matrix[0][col] * calc3Determ(minor);
    }
    return det;
}

int main() {
    std::vector<std::vector<int>> dots;
    
    dots.resize(4);

    std::cout << "Input dot coordinates" << std::endl;

    for (int i = 0; i < 4; i++) {
        dots[i].resize(3);
        for (int j = 0; j < 3; j++) {
            std::cin >> dots[i][j];
        }
    }

    std::vector<std::vector<int>> matrix = {
        {dots[0][0], dots[0][1], dots[0][2], 1},
        {dots[1][0], dots[1][1], dots[1][2], 1},
        {dots[2][0], dots[2][1], dots[2][2], 1},
        {dots[3][0], dots[3][1], dots[3][2], 1},
    };

    int n1 = dots[0][0]*dots[0][0] + dots[0][1]*dots[0][1] + dots[0][2]*dots[0][2];
    int n2 = dots[1][0]*dots[1][0] + dots[1][1]*dots[1][1] + dots[1][2]*dots[1][2];
    int n3 = dots[2][0]*dots[2][0] + dots[2][1]*dots[2][1] + dots[2][2]*dots[2][2];
    int n4 = dots[3][0]*dots[3][0] + dots[3][1]*dots[3][1] + dots[3][2]*dots[3][2];

    std::vector mA = matrix;
    mA[0][0] = n1;
    mA[1][0] = n2;
    mA[2][0] = n3;
    mA[3][0] = n4;

    std::vector mB = matrix;
    mB[0][1] = n1;
    mB[1][1] = n2;
    mB[2][1] = n3;
    mB[3][1] = n4;

    std::vector mC = matrix;
    mC[0][2] = n1;
    mC[1][2] = n2;
    mC[2][2] = n3;
    mC[3][2] = n4;

    std::vector mD = matrix;
    mD[0][3] = n1;
    mD[1][3] = n2;
    mD[2][3] = n3;
    mD[3][3] = n4;

    double det = calc4Determ(matrix);

    if (det == 0) {
        std::cout << "Impossible to define a shape" << std::endl;
        return 0;
    }

    double detA = calc4Determ(mA);
    double detB = calc4Determ(mB);
    double detC = calc4Determ(mC);
    double detD = calc4Determ(mD);
    
    double A = detA/det; 
    double B = detB/det; 
    double C = detC/det; 
    double D = detD/det;
    
    double x0 = -A/2;
    double y0 = -B/2;
    double z0 = -C/2;

    double r = sqrt(x0*x0 + y0*y0 + z0*z0 - D);
    
    printf("%lf^2 = (x %c %lf)^2 + (y %c %lf)^2 + (z %c %lf)^2 \n",
        r,
       (x0 < 0 ? '+' : '-'), fabs(x0),
       (y0 < 0 ? '+' : '-'), fabs(y0),
       (z0 < 0 ? '+' : '-'), fabs(z0));

    return 0;
}