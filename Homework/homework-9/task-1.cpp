#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> ptr {std::make_unique<int>(10)};
    std::cout << *ptr << std::endl;
    ptr.reset(new int(25));
    std::cout << *ptr << std::endl;
    return 0;
}