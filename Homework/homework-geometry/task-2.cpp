#include <iostream>
#include <cmath>

using namespace std;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double perimeter(double dots[4][2]){
    double perimeter = 0.0;
    for (int i = 0; i < 4; ++i) {
        int j = (i + 1) % 4;
        perimeter += dist(dots[i][0], dots[i][1], dots[j][0], dots[j][1]);
    }    
    return perimeter;
    
}

int main() {
    const int dots = 4;
    const int cords = 2;

    double arr[dots][cords];

    double* p = *arr;

    for (int i = 0; i < dots*cords; i++) {
        cin >> *(p + i);
    }

    std::cout << "Perimeter is: " << perimeter(arr) << std::endl;
    return 0;
}
