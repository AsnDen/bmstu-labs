#include <iostream>
#include <memory>

int main() {\

    std::shared_ptr<int> ptr1 {std::make_shared<int>(5)};
    
    std::cout << ptr1.use_count() << std::endl;

    std::shared_ptr<int> ptr2 {ptr1};
    
    std::cout << ptr1.use_count() << std::endl;

    std::shared_ptr<int> ptr3 {ptr1};
    
    std::cout << ptr1.use_count() << std::endl;

    ptr3.reset();

    std::cout << ptr1.use_count() << std::endl;

    return 0;
}