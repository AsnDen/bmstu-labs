#include <iostream>
#include <cmath>

using namespace std;

double dist(double x1, double x2, double y1, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx*dx + dy*dy);
}

int main() {

    double x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y1;

    cout << "Distance is " << dist(x1, x2, y1, y2) << endl; 

    return 0;
}