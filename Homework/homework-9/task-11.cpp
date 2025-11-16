#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

void showVec(std::vector<double> v) {
    for (size_t i{}; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main() {

    size_t n;
    std::cin >> n;
    std::vector<double> v{};

    for (size_t i{}; i < n; i++) {
        double temp{};
        std::cin >> temp;
        v.push_back(temp);
    }

    std::cout << "Original data: ";
    showVec(v);

    std::unique_ptr<double[]> arr {std::make_unique<double[]>(n)};

    for (size_t i{}; i < n; i++) arr[i] = v[i];

    auto mean = [](double* data, size_t size){
        double sm{};
        for (size_t i{}; i < size; i++) sm+=data[i];
        return sm / size;
    };

    auto mx = std::max_element(v.begin(), v.end());
    
    auto normalize = [&n](double* data, auto maximum){
        for (size_t i{}; i < n; i++) data[i] /= *maximum;
    };

    auto copyBack = [&v](double* data, size_t size){
        for (size_t i{}; i < size; i++) v[i] = data[i]; 
    };

    std::cout << "Mean: " << mean(arr.get(), n) << std::endl;

    normalize(arr.get(), mx);

    copyBack(arr.get(), n);
    std::cout << "Normalized data: ";
    showVec(v);

    return 0;
}