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
    
    for (int v : vec) std::cout << v << " ";
    std::cout << std::endl;

    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int x){
        return x < 0;
    }), vec.end());

    for (int v : vec) std::cout << v << " ";

    return 0;
}