#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(){
    
    std::vector<int> vec;
    int inp;

    for (int i = 0; i < 30; i++) {
        std::cin >> inp;
        vec.push_back(inp);
    }

    int total {std::accumulate(vec.begin(), vec.end(), 0)};
    double average {double(total) / vec.size()};

    printf("Total kWh: %d\n", total);
    printf("Average kWh: %f\n", average);

    auto mima = std::minmax_element(vec.begin(), vec.end());

    printf("Days with min kWh consumption: ");
    int day {1};
    std::for_each(vec.begin(), vec.end(), [&day, mima](int x){
        if (x == *mima.first) printf("%d ", day);
        day++;
    });
    printf("\n");

    printf("Days with max kWh consumption: ");
    day = {1};
    std::for_each(vec.begin(), vec.end(), [&day, mima](int x){
        if (x == *mima.second) printf("%d ", day);
        day++;
    });
    printf("\n");

    vec.erase(std::remove_if(vec.begin(), vec.end(), [average](int x){
        return !(x > 1.2*average);
    }), vec.end());

    for (int v : vec) printf("%d ", v);

    return 0;
}