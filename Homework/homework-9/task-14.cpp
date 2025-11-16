#include <iostream>
#include <memory>
#include <vector>

int main() {

    size_t n{}, m{};
    std::cin >> n >> m;

    std::unique_ptr<double[]> matrix(new double[n*m]);

    for (size_t i{}; i < n; i++) for (size_t j{}; j < m; j++) {
        std::cin >> matrix[i*n+j];
    }

    auto sumColumns = [](double arr[], size_t n, size_t m){
        std::vector<double> v{};
        for (size_t j{}; j < m; j++) {
            double sm{};
            for (size_t i{}; i < n; i++) {
                sm += arr[i*n+j];
            }
            v.push_back(sm);
        }
        return v;
    };

    auto maxIndex = [](std::vector<double> v){
        size_t ind{};
        double mx{v[0]};
        for (size_t i{}; i < v.size(); i++) {
            if (v[i] > mx) {
                mx = v[i];
                ind = i;
            }
        }
        return ind;
    };

    std::vector<double> sums {sumColumns(matrix.get(), n, m)};
    size_t ind {maxIndex(sums)};

    std::cout << "Sums of columns: [";
    for (double c : sums) std::cout << c << ' ';
    std::cout << "]" << std::endl;

    std::cout << "Column with max sum is " << ind+1 << "("  << sums[ind] << ")" << std::endl;

    return 0;
}