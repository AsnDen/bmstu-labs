#include <iostream>
#include <vector>
#include <iomanip>

void showMatrix(const std::vector<std::vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[i].size(); j++) {
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "How many rows and lines are in the matrix?" << std::endl;
    std::cin >> n;
    std::vector<std::vector<int>> matrix;
    
    matrix.resize(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(n);
    }

    int m = 1, i = 0, j = 0;
    int maxi = n-1, mini = 0, maxj = n-1, minj = -1;
    while (m <= n*n) {
        matrix[i][j] = m;
        m++;

        if ((i == mini) && (j == maxj)) {
            minj++;
        } else if ((i == maxi) && (j == maxj)) {
            mini++;
        } else if ((i == maxi) && (j == minj)) {
            maxj--;            
        } else if ((i == mini) && (j == minj)) {
            maxi--;
        }

        if ((i == mini) && (j < maxj)) {
            j++;
        }
        else if ((j == maxj) && (i < maxi)) {
            i++;
        }
        else if ((i == maxi) && (j > minj)) {
            j--;
        }
        else if ((j == minj) && (i > minj)){
            i--;
        }
    }

    
    showMatrix(matrix);

    return 0;
}