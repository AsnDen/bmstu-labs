#include <iostream>
#include <iomanip>

double** allocatePlate(size_t rows, size_t cols, int temp=0) {
    double** plate {new double*[rows]{}};

    for (size_t i{}; i < rows; i++) plate[i] = new double[cols]{};

    for (size_t i{}; i < rows; i++) {
        for (size_t j{}; j < cols; j++) {
            plate[i][j] = temp;
        }
    }

    return plate;
}

void placeHeater(double** plate, size_t rows, size_t cols) {
    plate[rows/2][cols/2] = 100;
}


void freePlate(double **plate, size_t n) {
    for (size_t i{}; i < n; i++) {
        delete[] plate[i];
        plate[i] = nullptr;
    }
    delete[] plate;
    plate = nullptr;
}

void updateTemperature(double** plate, size_t rows, size_t cols) {
    double** newPlate {allocatePlate(rows, cols)};
    
    for (size_t i{}; i < rows; i++) for (size_t j{}; j < cols; j++) {
        if ((i == rows/2) && (j == cols/2)) {
            newPlate[i][j] = 100;
            continue;
        }
        
        double newTemp{};
        unsigned int neighbours{};
        if (i != 0) {newTemp += plate[i-1][j]; neighbours++;}
        if (i != rows-1) {newTemp += plate[i+1][j]; neighbours++;}
        if (j != 0) {newTemp += plate[i][j-1]; neighbours++;}
        if (j != cols-1) {newTemp += plate[i][j+1]; neighbours++;}

        newPlate[i][j] = newTemp/neighbours;
    }

    for (size_t i{};i < rows; i++) for (size_t j{}; j < cols; j++) {
        plate[i][j] = newPlate[i][j];
    }

    freePlate(newPlate, rows);

}

void showPlate(double** plate, size_t rows, size_t cols) {
    std::cout << std::left;

    for (size_t i{}; i < rows; i++) {
        for (size_t j{}; j < cols; j++) {
            std::cout << std::setw(7) << std::setprecision(4) << *(*(plate+i)+j);
        }
        std::cout << std::endl;
    }

    std::cout << std::right;
}

int main() {

    size_t rows{}, cols{}, iterations{};
    unsigned int DEFAULT_TEMP {20};

    std::cout << "Enter rows and colums" << std::endl;

    std::cin >> rows >> cols;

    std::cout << "Enter nubmer of iterations" << std::endl;

    std::cin >> iterations;

    double** plate = allocatePlate(rows, cols, DEFAULT_TEMP);

    placeHeater(plate, rows, cols);

    for (size_t i{}; i < iterations; i++) {
        updateTemperature(plate, rows, cols);
        std::cout << "------------" << std::endl;
    }
    
    showPlate(plate, rows, cols);

    freePlate(plate, rows);

    return 0;
}