#include <iostream>
#include <memory>
#include <iomanip>

int main() {
    size_t n = 5;

    auto temperature {std::make_unique<double[]>(n)};
    auto pressure    {std::make_unique<double[]>(n)};
    auto humidity    {std::make_unique<double[]>(n)};

    double tempVals[] {25.4, 26.1, 24.8, 25.9, 26.3};
    double presVals[] {101.2, 100.9, 101.5, 101.0, 101.3};
    double humVals[]  {40.0, 42.5, 39.8, 41.0, 43.2};

    for (size_t i{}; i < n; ++i) {
        temperature[i] = tempVals[i];
        pressure[i]    = presVals[i];
        humidity[i]    = humVals[i];
    }

    auto mean = [n](double* arr) {
        double sum = 0;
        for (size_t i{}; i < n; ++i) sum += arr[i];
        return sum / n;
    };

    double tempMean = mean(temperature.get());
    double presMean = mean(pressure.get());
    double humMean  = mean(humidity.get());

    std::cout << std::setw(12) << "Temperature" << std::setw(15) << tempMean << std::endl;
    std::cout << std::setw(12) << "Pressure"    << std::setw(15) << presMean << std::endl;
    std::cout << std::setw(12) << "Humidity"    << std::setw(15) << humMean  << std::endl;

    return 0;
}
