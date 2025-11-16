#include <iostream>
#include <algorithm>

void swapPointers(int **a, int **b) {
    std::swap(**a, **b);
}

int main() {

    int x, y;
    int *p1 = &x;
    int *p2 = &y;

    printf("%#p %d %#p %d\n", p1, *p1, p2, *p2);

    swapPointers(&p1, &p2);

    printf("%#p %d %#p %d\n", p1, *p1, p2, *p2);

    return 0;
}