#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(){
    
    std::vector<double> vec;
    double inp;

    for (int i = 0; i < 24; i++) {
        std::cin >> inp;
        vec.push_back(inp);
    }

    std::vector<double> def(vec.size());

    auto mima {std::minmax_element(vec.begin(), vec.end())};
    double sm {double(std::accumulate(vec.begin(), vec.end(), 0.0))};
    double average {sm / vec.size()};
    
    printf("Sum of consumption is %f. Average consumption %f\n", sm, average);

    printf("Hours of max consumption: ");

    std::for_each(vec.begin(), vec.end(), [mima](double x){
        if (x == *mima.second) printf("%f ", x);
    });

    std::transform(vec.begin(), vec.end(), def.begin(), [average](double x){
        return x - average;
    });

    printf("\nDeflection of each hour: ");

    std::for_each(def.begin(), def.end(), [](double x){
        printf("%f ", x);
    });

    std::sort(vec.begin(), vec.end());

    printf("\nTop 5 min: ");

    std::for_each(vec.begin(), vec.begin()+5, [](double x){
        printf("%f ", x);
    });
    printf("\n");

    return 0;
}