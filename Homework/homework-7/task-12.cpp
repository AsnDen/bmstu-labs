#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec {5, 5, 10, -1, 0};

    int* p = vec.data();

    for (int i = 0; i < vec.size(); i++) {
        *p += 10;
        printf("%d ", *p);
        p++;
    }

    return 0;
}