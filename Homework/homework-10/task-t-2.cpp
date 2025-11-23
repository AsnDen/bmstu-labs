#include <chrono>
#include <iostream>
#include <thread>

int main() {

    using namespace std::chrono_literals;

    size_t n{};
    std::cin >> n;

    while (n > 0) {
        std::cout << n-- << " seconds remaining" << std::endl; 
        std::this_thread::sleep_for(1s);
    }

    std::cout << "Time is gone" << std::endl;

    return 0;
}