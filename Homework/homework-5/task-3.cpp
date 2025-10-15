#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    
    std::vector<int> vec;
    int inp;

    for (int i = 0; i < 20; i++) {
        std::cin >> inp;
        vec.push_back(inp);
    }

    std::cout << *std::max_element(vec.begin(), vec.end()) << std::endl;

    int mx = vec[0];
    std::for_each(vec.begin(), vec.end(), [&mx](int x){
        if (mx < x) {
            mx = x;
        }
    });

    std::cout << mx << std::endl;

    return 0;
}