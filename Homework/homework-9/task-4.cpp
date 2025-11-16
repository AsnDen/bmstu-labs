#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> ptr1 {std::make_unique<int>(42)};

    std::unique_ptr<int> ptr2 {std::move(ptr1)};

    (!ptr1) && (ptr2) ? std::cout << "Yea" : std::cout << "Nah";
    std::cout << std::endl;

    return 0;
}