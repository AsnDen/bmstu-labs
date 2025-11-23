#include <chrono>
#include <iostream>

int mySum(size_t n) {
    size_t sm{};
    for (size_t i{1}; i < n+1; i++) {
        sm += i;
    }
    return sm;
}

int main() {

    size_t n{};
    std::cin >> n;

    auto start {std::chrono::high_resolution_clock::now()};

    mySum(n);

    auto end {std::chrono::high_resolution_clock::now()};

    auto duration {std::chrono::duration_cast<std::chrono::milliseconds>(end-start)};

    std::cout << "Time of execution is " << duration << std::endl;

    return 0;
}