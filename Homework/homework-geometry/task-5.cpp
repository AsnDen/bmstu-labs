#include <iostream>

using namespace std;

double solution(double x1, double y1, double x2, double y2, double x3, double y3) {
    return (x3 - x2)/(x2 - x1) == (y3 - y2)/(y2-y1);
}

int main() {
    const int dots = 3;
    const int cords = 2;

    double arr[dots][cords];

    double* p = *arr;

    for (int i = 0; i < dots*cords; i++) {
        cin >> *(p + i);
    }

    cout << solution(arr[0][0], arr[0][1], arr[1][0], arr[1][1], arr[2][0] ,arr[2][1]) << endl;
    return 0;
    
}
