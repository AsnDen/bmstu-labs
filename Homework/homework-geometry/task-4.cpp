#include <iostream>
#include <cmath>

using namespace std;

struct dot {
    double x, y;
};

double dist(dot first, dot second) {
    double dx = first.x - second.x;
    double dy = first.y - second.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {

    double x1, x2, y1, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    
    dot dot1 = {x1, y1};
    dot dot2 = {x2, y2};
    dot dot3 = {x3, y3};
    dot dot4 = {x4, y4};

    dot arr[] = {dot1, dot2, dot3, dot4};

    double mx = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 4; j++) {
            double dst = dist(arr[i], arr[j]);
            if (dst > mx) {
                mx = dst;
            }
        }
    }

    cout << "Diag is " << mx << endl; 

    return 0;
}