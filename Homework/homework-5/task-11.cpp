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
        return x < 0.1;
    }), vec.end());

    auto mima = std::minmax_element(vec.begin(), vec.end());

    printf("Average is %f. Max is %f\n", double(std::accumulate(vec.begin(), vec.end(), 0.0)) / vec.size(), *mima.second);

    if (*mima.first > 0.5) printf("All values are above 0.5\n");
    else printf("Some values are below 0.5\n");

    std::sort(vec.begin(), vec.end());

    std::cout << "10 max values are: " << std::endl;

    std::for_each(vec.end()-10, vec.end(), [](double x){
        printf("%f ", x);
    });
    
    return 0;
}