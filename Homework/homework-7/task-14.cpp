#include <iostream>
#include <vector>
#include <cmath>

double computeRMS(const std::vector<double>& signal) {
    const double* p = signal.data();
    double rms {0};

    for (int i = 0; i < signal.size() - 1; i++) {
        rms += pow(*(p+i), 2);
    }

    rms /= signal.size();
    return sqrt(rms);
}

int main() {

    std::vector<double> signal {2.0, 3.0, 1.0, 4.0, 3.0};

    std::cout << "RMS value: " << computeRMS(signal) << std::endl;

    return 0;
}