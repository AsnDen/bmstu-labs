#include <iostream>
#include <vector>
#include <algorithm>
#include <format>
#include <numeric>

int main(){
    
    std::vector<double> vec;
    double inp;

    for (int i = 0; i < 10; i++) {
        std::cin >> inp;
        vec.push_back(inp);
    }

    vec.erase(std::remove_if(vec.begin(), vec.end(), [](double x){
        return !(-50 <= x && x <= 50);
    }), vec.end());

    auto mima = std::minmax_element(vec.begin(), vec.end());

    std::cout << std::format("Average is {}, min is {}, max is {}\n",
        double(std::accumulate(vec.begin(), vec.end(), 0)) / vec.size(),
        *mima.first,
        *mima.second);
    
    if (*mima.first <= -10) {
        std::cout << "There are temperatures that are below -10 degrees" << std::endl;
    }else {
        std::cout << "All temperatures are higher than -10 degrees" << std::endl;
    }

    for (double v : vec) std::cout << v << " ";

    return 0;
}