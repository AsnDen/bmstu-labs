#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    
    std::vector<int> vec;
    
    for (int i = 1; i <= 10; i++) {
        vec.push_back(i);
    }

    std::for_each(vec.begin(), vec.end(), [](int x){
        std::cout << x << " ";
    });
    std::cout << std::endl;

    return 0;
}