#include <iostream>
#include <vector>
#include <memory>

void processA(std::shared_ptr<std::vector<int>> buf) {
    for (auto& val : *buf) {
        val += 1;
    }
}

void processB(std::shared_ptr<std::vector<int>> buf) {
    for (auto& val : *buf) {
        val *= 2;
    }
}

int main() {
    auto buffer = std::make_shared<std::vector<int>>();

    for (int i = 1; i <= 10; ++i) {
        buffer->push_back(i);
    }

    processA(buffer);
    processB(buffer);
    
    std::cout << "Result: ";
    for (int val : *buffer) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
