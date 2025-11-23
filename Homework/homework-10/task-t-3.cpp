#include <chrono>
#include <iostream>

int main() {

    size_t n{};
    std::cin >> n;

    auto seconds {std::chrono::seconds(n)};
    auto hours {std::chrono::duration_cast<std::chrono::hours>(seconds)};
    seconds -= hours;
    auto minutes {std::chrono::duration_cast<std::chrono::minutes>(seconds)};
    seconds -= minutes;
    std::cout << hours << ' ' << minutes << ' ' << seconds << std::endl;
    return 0;
}