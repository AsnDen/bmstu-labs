#include <iostream>
#include <memory>

void fillArray(std::unique_ptr<int[]>& arr, int n) {
    for (size_t i{}; i < n; i++) arr[i] = i*i;
}

int main() {

    size_t n{};
    std::cin >> n;

    std::unique_ptr<int[]> arr {std::make_unique<int[]>(n)};

    fillArray(arr, n);

    for (size_t i{}; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}