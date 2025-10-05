#include <iostream>
#include <cmath>

using namespace std;

struct dot {
    double x, y;
};

double defineDotPosition(dot dx, dot d1, dot d2) {
    return (d2.x - d1.x) * (dx.y - d1.y) - (d2.y - d1.y) * (dx.x - d1.x);
}

double dist(dot d1, dot d2) {
    double dx = d1.x - d2.x;
    double dy = d1.y - d2.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    dot d1, d2, d3, d4; 
    cin >> d1.x >> d1.y;
    cin >> d2.x >> d2.y;
    cin >> d3.x >> d3.y;
    cin >> d4.x >> d4.y;

    dot dots[4] = {d1, d2, d3, d4};

    // Count all dists
    double perimeter = dist(d1, d2) + dist(d1, d3) + dist(d1, d4) + dist(d2, d3) + dist(d2, d4) + dist(d3,d4);

    // Find diag
    if (defineDotPosition(d3, d1, d2) * defineDotPosition(d4, d1, d2) < 0) {
        perimeter -= (dist(d1,d2) + dist(d3,d4));
    }
    
    if (defineDotPosition(d2, d1, d3) * defineDotPosition(d4, d1, d3) < 0) {
        perimeter -= (dist(d1,d3) + dist(d2,d4));
    }
    
    if (defineDotPosition(d2, d1, d4) * defineDotPosition(d3, d1, d4) < 0) {
        perimeter -= (dist(d1,d4) + dist(d2,d3));
    }

    cout << "Perimeter is " << perimeter << endl;

    return 0;
}