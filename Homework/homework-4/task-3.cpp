#include <iostream>
#include <vector>
#include <algorithm>
#include <print>

struct dot {
    int i, j, val;
    bool operator==(const dot& other) const {
        return i == other.i && j == other.j;
    }
};

std::vector<dot> findRowMins(std::vector<std::vector<int>> matrix) {
    int n = matrix.size();
    std::vector<dot> mins;
    for (int i = 0; i < n; i++) {
        int mn = matrix[i][0];
        
        for (int j = 0; j < matrix[i].size(); j++){
            mn = std::min(mn, matrix[i][j]);
        }

        // In case there are dublicates
        for (int j = 0; j < matrix[i].size(); j++){
            if (matrix[i][j] == mn) {
                mins.push_back({i, j, matrix[i][j]});
            }
        
        }
    }
    

    return mins;
}

std::vector<dot> findRowMaxs(std::vector<std::vector<int>> matrix) {
    int n = matrix.size();
    std::vector<dot> maxs;
    for (int i = 0; i < n; i++) {
        int mx = matrix[i][0];
        
        for (int j = 0; j < matrix[i].size(); j++){
            mx = std::max(mx, matrix[i][j]);
        }

        // In case there are dublicates
        for (int j = 0; j < matrix[i].size(); j++){
            if (matrix[i][j] == mx) {
                maxs.push_back({i, j, matrix[i][j]});
            }
        
        }
    }
    return maxs;
}

std::vector<dot> findLineMins(std::vector<std::vector<int>> matrix) {
    int n = matrix[0].size();
    int m = matrix.size();
    std::vector<dot> mins;
    for (int j = 0; j < n; j++) {
        int mn = matrix[0][j];
        
        for (int i = 0; i < m; i++){
            mn = std::min(mn, matrix[i][j]);
        }

        // In case there are dublicates
        for (int i = 0; i < m; i++){
            if (matrix[i][j] == mn) {
                mins.push_back({i, j, matrix[i][j]});
            }
        
        }
    }
    

    return mins;
}

std::vector<dot> findLineMaxs(std::vector<std::vector<int>> matrix) {
    int n = matrix[0].size();
    int m = matrix.size();
    std::vector<dot> maxs;
    for (int j = 0; j < n; j++) {
        int mx = matrix[0][j];
        
        for (int i = 0; i < m; i++){
            mx = std::max(mx, matrix[i][j]);
        }

        // In case there are dublicates
        for (int i = 0; i < m; i++){
            if (matrix[i][j] == mx) {
                maxs.push_back({i, j, matrix[i][j]});
            }
        
        }
    }
    return maxs;
}

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

    std::vector<dot> rowMins = findRowMins(matrix);
    std::vector<dot> rowMaxs = findRowMaxs(matrix);
    std::vector<dot> lineMins = findLineMins(matrix);
    std::vector<dot> lineMaxs = findLineMaxs(matrix);

    std::vector<dot> typeA;
    std::vector<dot> typeB;

    for (dot fst : rowMins) {
        for (dot snd : lineMaxs) {
            if (fst == snd) {
                typeA.push_back(fst);
            }
        }
    }

    for (dot fst : rowMaxs) {
        for (dot snd : lineMins) {
            if (fst == snd) {
                typeB.push_back(fst);
            }
        }
    }

    for (dot dt : typeA) {
        std::printf("A %d %d %d\n", dt.val, dt.i+1, dt.j+1); 
    }

    
    for (dot dt : typeB) {
        std::printf("B %d %d %d\n", dt.val, dt.i+1, dt.j+1); 
    }

    return 0;
}