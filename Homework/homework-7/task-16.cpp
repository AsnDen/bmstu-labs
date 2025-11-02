#include <iostream>
#include <vector>

void analyzePressure(const std::vector<double>& data, double& minVal, double& maxVal, double& avgVal) {

    const double* p = data.data();

    minVal = *p;
    maxVal = *p;
    avgVal = 0;

    for (int i = 0; i < data.size(); i++) {
        if (maxVal < *(p+i)) maxVal = *(p+i);
        if (minVal > *(p+i)) minVal = *(p+i);
        avgVal += *(p+i);
    }
    avgVal /= data.size();

}

int main() {

    std::vector<double> pressure = {101.3, 100.8, 101.9, 100.5, 102.0};

    double mn, mx, av;

    analyzePressure(pressure, mn, mx, av);

    printf("Min pressure: %f\nMax pressure: %f\nAverage pressure: %f\n", mn, mx, av);

    return 0;
}