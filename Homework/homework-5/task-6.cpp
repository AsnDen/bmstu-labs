#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    
    std::vector<int> vec;
    int inp;

    for (int i = 0; i < 20; i++) {
        std::cin >> inp;
        vec.push_back(inp);
    }

    std::cout << (std::find(vec.begin(), vec.end(), 7) != vec.end() ? "7 is among digits" : "7 is not among digits") << std::endl;

    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

    for (int v : vec) std::cout << v << " ";
    std::cout << std::endl;

    return 0;
}