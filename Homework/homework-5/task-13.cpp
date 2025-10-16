#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(){
    
    std::vector<double> vec;
    double inp;

    for (int i = 0; i < 50; i++) {
        std::cin >> inp;
        vec.push_back(inp);
    }

    vec.erase(std::remove_if(vec.begin(), vec.end(), [](double x){
        return (x < 0 || x > 12);
    }), vec.end());

    auto mima {std::minmax_element(vec.begin(), vec.end())};
    double average {double(std::accumulate(vec.begin(), vec.end(), 0.0)) / vec.size()};
    
    printf("Min pressure is %f. Max pressure is %f. Average pressure is %f\n", *mima.first, *mima.second, average);

    std::for_each(vec.begin(), vec.end(), [](double x){
        if (x > 8.0) printf("%f ", x);
    });

    return 0;
}