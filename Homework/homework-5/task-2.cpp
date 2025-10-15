#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    
    std::vector<int> vec;
    int inp;

    for (int i = 0; i < 10; i++) {
        std::cin >> inp;
        vec.push_back(inp);
    }

    std::for_each(vec.begin(), vec.end(), [](int x){
        std::cout << x*2 << " ";
    });
    std::cout << std::endl;

    return 0;
}