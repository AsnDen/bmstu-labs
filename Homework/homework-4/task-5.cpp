#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cout << "How many rows and lines (2 digits) are in the matrix?" << std::endl;
    std::cin >> n >> m;
    
    std::cout << "Fill the matrix" << std::endl;
    std::vector<std::vector<int>> matrix;
    
    matrix.resize(n);

    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }

    int z = 1, i = 0, j = 0;
    int maxi = n-1, mini = 0, maxj = m-1, minj = -1;
    while (z <= n*m) {
        std::cout << matrix[i][j] << " ";
        z++;

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

    std::cout << std::endl;

    return 0;
}