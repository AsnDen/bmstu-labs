#include <iostream>
#include <memory>

int main() {

    size_t n{};
    std::cin >> n;

    std::unique_ptr<int[]> arr {std::make_unique<int[]>(n)};

    for (size_t i{}; i < n; i++) {
        arr[i] = i+1;
    }

    for (size_t i{}; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}