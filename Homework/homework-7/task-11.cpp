#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec {5, 5, 10, -1, 0};

    int* p = &vec[0];

    int sum = 0;

    for (int i = 0; i < vec.size(); i++) {
        sum += *p++;
    }

    printf("%d", sum);

    return 0;
}