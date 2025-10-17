#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void print(std::vector<double>) {

}

int main(){
    
    int c {5};
    int t {30};
    int p {100};

    std::vector<std::vector<double>> temp(c, std::vector<double>(t));
    std::vector<std::vector<double>> pressure(c, std::vector<double>(p));

    double inp;

    for (std::vector<double>& v : temp) {
        for (int i = 0; i < t; i++) {
            std::cin >> inp;
            v[i] = {inp};
        }
    }

    for (std::vector<double>& v : pressure) {
        for (int i = 0; i < p; i++) {
            std::cin >> inp;
            v[i] = {inp};
        }
    }


    std::vector<double> t_average(c);

    std::transform(temp.begin(), temp.end(), t_average.begin(), [](std::vector<double> v){
        return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
    });

    std::vector<std::pair<std::vector<double>::iterator, std::vector<double>::iterator>> p_mima(c);

    std::transform(pressure.begin(), pressure.end(), p_mima.begin(), [](std::vector<double> v){
        return std::minmax_element(v.begin(), v.end());
    });

    std::vector<std::vector<double>> t_dev(c, std::vector<double>(t-1));

    std::transform(temp.begin(), temp.end(), t_dev.begin(), [t](std::vector<double> v){
        std::vector<double> tem(t-1);
        std::transform(v.begin()+1, v.end(),
        v.begin(),
        tem.begin(), [](double x, double y){
            return x - y;            
        });
        return tem;
    });

    std::vector<double> t_difference(c);

    std::transform(temp.begin(), temp.end(), t_difference.begin(), [](std::vector<double> v){
        auto mima = std::minmax_element(v.begin(), v.end());
        return *mima.second - *mima.first;
    });

    for (int i = 0; i < c; ++i) {
        auto [min_it, max_it] = p_mima[i];
        double minv = *min_it, maxv = *max_it;
        std::transform(pressure[i].begin(), pressure[i].end(), pressure[i].begin(),
                    [minv, maxv](double x){ return (x - minv) / (maxv - minv); });
    }

    std::for_each(pressure.begin(), pressure.end(), [](std::vector<double> v){
        std::for_each(v.begin(), v.end(), [](double x){
            if  (x > 0.9) printf("%f ", x);});
    });
    

    auto max_it = std::max_element(t_average.begin(), t_average.end());
    int max_index = std::distance(t_average.begin(), max_it);
    printf("\nMax avarage temp is: %d\n", max_index + 1);
    std::sort(t_average.begin(), t_average.end());

    return 0;
}