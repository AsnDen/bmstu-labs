#include <iostream>
#include <vector>

double *averageLoadPerNode(int **load, size_t n, size_t t) {
    double *averages {new double[n]{}};
    for (size_t i{}; i < n; i++) {
        double sum{};
        for (size_t j{}; j < t; j++) {
            sum += *(*(load + i) + j);
        }
        averages[i] = sum / t;
    }
    return averages;
}

void normalizeLoad(int **load, int n, int t) {
    double *averages = averageLoadPerNode(load, n, t);

    for (size_t i{}; i < n; i++) {
        if (averages[i] <= 80.0) {
            continue;
        }
        
        for (size_t j{}; j < t; j++) {
            int current = load[i][j];
            
            int tenPercent = current / 10;

            int share = tenPercent / (n - 1);

            load[i][j] = current - tenPercent;

            for (size_t k{}; k < n; k++) {
                if (k == i) continue;

                load[k][j] += share;
                if (load[k][j] > 100) load[k][j] = 100;
            }
        }
    }
    delete[] averages;
    averages = nullptr;
}


void normalizeLoad(int **load, size_t n, size_t t) {
    double *averages = averageLoadPerNode(load, n, t);
    
    for (size_t j{}; j < t; j++) {
        for (size_t i{}; i < n; i++) {
            if (averages[i] > 80.0) {
                
                
                int overload = *(*(load + i) + j) - 80;
                int transfer = overload / (n - 1);
                *(*(load + i) + j) = 80;
                
                for (int k = 0; k < n; k++) {
                    if (k != i) {
                        *(*(load + k) + j) += transfer;
                        if (*(*(load + k) + j) > 100) {
                            *(*(load + k) + j) = 100;
                        }
                    }
                }
            }
        }
    }
    
    delete[] averages;
    averages = nullptr;
}

std::pair<int, int> findCriticalInterval(int **load, size_t n, size_t t) {
    int maxSum{}, criticalInterval{};
    
    for (size_t j{}; j < t; j++) {
        int sum{};
        for (size_t i{}; i < n; i++) {
            sum += *(*(load + i) + j);
        }
        if (sum > maxSum) {
            maxSum = sum;
            criticalInterval = j;
        }
    }
    return {criticalInterval, maxSum};
}

void printMatrix(int **load, size_t n, size_t t) {
    for (size_t i{}; i < n; i++) {
        std::cout << "Node " << i << ": ";
        for (size_t j{}; j < t; j++) {
            std::cout << *(*(load + i) + j) << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    size_t n{}, t{};
    std::cout << "Enter the numbers of nodes and intervals: ";
    std::cin >> n >> t;
    
    int **load {new int*[n]{}};
    for (size_t i{}; i < n; i++) {
        load[i] = new int[t];
        std::cout << "Node " << i << ": ";
        for (size_t j{}; j < t; j++) {
            std::cin >> load[i][j];
        }
    }
    std::cout << std::endl;

    std::cout << "Analysis of load" << std::endl;
    printMatrix(load, n, t);
    
    double *averages {averageLoadPerNode(load, n, t)};
    bool needNormalization {false};
    std::cout << "Average load:" << std::endl;
    for (size_t i{}; i < n; i++) {
        std::cout << "Node " << i << ": " << averages[i] << "%" << std::endl;
        if (averages[i] > 80) needNormalization = true;
    }

    if (needNormalization) {
        normalizeLoad(load, n, t);
        std::cout << "After normalization:" << std::endl;
        printMatrix(load, n, t);
    }
    
    std::pair<int, int> critical {findCriticalInterval(load, n, t)};
    std::cout << "Critical interval: " << critical.first << " (load is " << critical.second << "%)"  << std::endl;
    
    delete[] averages;
    averages = nullptr;
    for (int i = 0; i < n; i++) {
        delete[] load[i];
        load[i] = nullptr;
    }
    delete[] load;
    load = nullptr;
    
    return 0;
}