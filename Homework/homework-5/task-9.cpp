#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

double findMadian(std::vector<double> v) {
    if (v.size() % 2 == 0) {
        return (v[v.size()/2] + v[v.size()/2-1]) / 2;
    }
    return v[v.size()/2];
}


int main(){
    
    std::vector<double> vec;
    double inp;

    for (int i = 0; i < 20; i++) {
        std::cin >> inp;
        vec.push_back(inp);
    }

    vec.erase(std::remove_if(vec.begin(), vec.end(), [](double x){
        return x < 0;
    }), vec.end());

    auto mima = std::minmax_element(vec.begin(), vec.end());

    std::cout << std::format("Average is {}, min is {}, max is {}\n",
        double(std::accumulate(vec.begin(), vec.end(), 0)) / vec.size(),
        *mima.first,
        *mima.second);
    
    if (*mima.first >= 10 && *mima.second <= 90) {
        std::cout << "Engine was working in range from 10 to 90 kW" << std::endl;
    } else {
        std::cout << "Engine was not working in range from 10 to 90 kW" << std::endl;
    }
    
    std::sort(vec.begin(), vec.end());
    
    std::cout << "Median is " << findMadian(vec) << std::endl; //REDO

    return 0;
}