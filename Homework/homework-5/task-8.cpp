#include <iostream>
#include <vector>
#include <algorithm>
#include <format>
#include <numeric>

int main(){
    
    std::vector<double> vec;
    double inp;

    for (int i = 0; i < 50; i++) {
        std::cin >> inp;
        vec.push_back(inp);
    }

    vec.erase(std::remove_if(vec.begin(), vec.end(), [](double x){
        return x > 120;
    }), vec.end());

    auto mn = std::min_element(vec.begin(), vec.end());

    std::cout << std::format("Average is {}\n",
        double(std::accumulate(vec.begin(), vec.end(), 0)) / vec.size());
    
    if (*mn > 0){
        std::cout << "Car was always moving" << std::endl;
    }else {
        std::cout << "Car was not always moving" << std::endl;
    }

    std::sort(vec.begin(), vec.end());

    std::cout << "Max values are: " << std::endl;

    std::for_each(vec.begin()+40, vec.end(), [](double x){
        std::cout << x << " ";
    });
    
    std::cout << std::endl;

    return 0;
}