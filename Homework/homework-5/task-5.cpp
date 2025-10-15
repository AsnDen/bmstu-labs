#include <iostream>
#include <vector>
#include <algorithm>
#include <print>
#include <numeric>

int main(){
    
    std::vector<int> vec;
    int inp;

    for (int i = 0; i < 20; i++) {
        std::cin >> inp;
        vec.push_back(inp);
    }

    auto mima = std::minmax_element(vec.begin(), vec.end());

    printf("Min is %d. Max is %d\n", *mima.first, *mima.second);

    printf("Average is %f\n", double(std::accumulate(vec.begin(), vec.end(), 0)) / 20);

    std::sort(vec.begin(), vec.end());

    printf("Median is is %f\n", double(vec[9] + vec[10]) / 2);

    return 0;
}