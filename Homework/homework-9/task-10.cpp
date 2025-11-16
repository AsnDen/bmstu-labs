#include <iostream>
#include <memory>

std::unique_ptr<int[]> createArray(size_t n) {
    std::unique_ptr<int[]> arr {std::make_unique<int[]>(n)};

    for (size_t i{}; i < n; i++) {
        arr[i] = i+1;
    }

    return arr;
}

int main() {

    size_t n{};
    std::cin >> n;

    std::unique_ptr<int[]> arr {createArray(n)};

    for (size_t i{}; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}