#include <iostream>
#include <cmath>

using namespace std;

double findShape(double* p) {
    double x1 = *p;
    double y1 = *(p+1);
    double x2 = *(p+2);
    double y2 = *(p+3);
    double x3 = *(p+4);
    double y3 = *(p+5);

    return 0.5*abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
}

int main() {

    const int dots = 3;
    const int cords = 2;

    double arr[dots][cords];

    double* p = *arr;

    for (int i = 0; i < dots*cords; i++) {
        cin >> *(p + i);
    }

    cout << findShape(*arr);

    return 0;
}