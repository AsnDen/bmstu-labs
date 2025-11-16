#include <iostream>
#include <iomanip>

double **allocateWeights(size_t rows, size_t cols) {
    double **weights {new double*[rows]};
    for (size_t i{}; i < rows; i++) {
        weights[i] = new double[cols];
        for (size_t j{}; j < cols; j++) {
            weights[i][j] = (rand() % 110 - 10) / 10.0;
        }
    }
    return weights;
}


void freeWeights(double **weights, size_t rows) {
    for (size_t i{}; i < rows; i++) {
        delete[] weights[i];
        weights[i] = nullptr;
    }
    delete[] weights;
    weights = nullptr;
}

double *forward(double **weights, double *inputs, size_t rows, size_t cols) {
    double *outputs {new double[rows]};
    for (size_t i{}; i < rows; i++) {
        outputs[i] = 0.0;
        for (size_t j{}; j < cols; j++) {
            outputs[i] += weights[i][j] * inputs[j];
        }
    }
    return outputs;
}

int main() {
    srand(time(0));
    size_t rows{4}, cols{5};

    double **weights {allocateWeights(rows, cols)};
    double *inputs {new double[cols]};
    
    for (size_t i{}; i < cols; i++) {
        inputs[i] = (rand() % 100) / 100.0;
    }
    
    std::cout << std::left;

    std::cout << "Matrix:" << std::endl;
    for (size_t i{}; i < rows; i++) {
        for (size_t j{}; j < cols; j++) {
            std::cout << std::setw(5) << weights[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << "Output:" << std::endl;
    for (size_t i{}; i < rows; i++) {
        std::cout << inputs[i] << " ";
    }
    std::cout << std::endl;
    
    double *outputs = forward(weights, inputs, rows, cols);
    
    std::cout << "Neuron output:" << std::endl;
    for (size_t i = 0; i < rows; i++) {
        std::cout << outputs[i] << " ";
    }
    std::cout << std::endl;
    
    freeWeights(weights, rows);
    delete[] inputs;
    inputs = nullptr;
    delete[] outputs;
    outputs = nullptr;
    
    return 0;
}