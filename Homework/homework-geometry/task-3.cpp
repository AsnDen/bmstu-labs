#include <iostream>
#include <cmath>

using namespace std;

double mean(double arr[], int n) {
    double s = 0;
    for (int i = 0; i < n; i++) {
        s += arr[i];
    }
    return s / n;

}

int main() {
    const int dots = 3;
    const int cords = 2;

    double arr[dots][cords];

    double* p = *arr;

    for (int i = 0; i < dots*cords; i++) {
        cin >> *(p + i);
    }

    double X[3];
    double Y[3];
    for (int i = 0; i < dots; i++) {
        X[i] = arr[i][0];
        Y[i] = arr[i][1];
    }
    std::cout << "Center has cords: " << mean(X, 3) << " " << mean(Y, 3) << std::endl;
    return 0;
}
