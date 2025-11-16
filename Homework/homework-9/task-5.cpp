#include <iostream>
#include <memory>

int main() {

    size_t n{}, m{};
    std::cin >> n >> m;

    std::unique_ptr<int[]> arr {std::make_unique<int[]>(n*m)};

    for (size_t i{}; i < n; i++) for (size_t j{}; j < m; j++) {
        arr[i*m + j] = i*j;
    }

    for (size_t i{}; i < n; i++) {
        for (size_t j{}; j < m; j++) {
            std::cout << arr[i*m + j] << " ";
        } 
        std::cout << std::endl;
    }

    return 0;
}