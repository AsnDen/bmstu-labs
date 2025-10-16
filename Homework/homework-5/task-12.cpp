#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

double findMedian(std::vector<double> v) {
    if (v.size() % 2 == 0) {
        return (v[v.size()/2] + v[v.size()/2-1]) / 2;
    }
    return v[v.size()/2];
}

int main(){
    
    std::vector<double> vec;
    double inp;

    for (int i = 0; i < 50; i++) {
        std::cin >> inp;
        vec.push_back(inp);
    }

    vec.erase(std::remove_if(vec.begin(), vec.end(), [](double x){
        return x < 0.1;
    }), vec.end());

    auto mima {std::minmax_element(vec.begin(), vec.end())};
    double average {double(std::accumulate(vec.begin(), vec.end(), 0.0)) / vec.size()};
    
    printf("Min amount of fuel is %f\n", *mima.first);

    if (*mima.first < *mima.second*0.95) printf("At some point fuel was below 95 of maximum\n");
    else printf("Fuel was always above 95 percent of maximum\n");

    printf("Total consumption is %f\n", *(vec.begin()) - *(vec.end()-1));

    std::sort(vec.begin(), vec.end());

    printf("Median is %f\n", findMedian(vec));

    return 0;
}