#include <iostream>
#include <cmath>

using namespace std;

struct dot {
    double x,y;
};

double findXCord(dot d1, dot d2, dot d3) {

    return (d2.x - d1.x) * (d3.y - d1.y) / (d2.y - d1.y) + d1.x;
}

bool isInside(dot dots[], int n, dot mainDot) {
    int counter = 0;

    for (int i = 0; i < n; ++i) {

        // If edge is horizontal we skip it 
        if (dots[i].y == dots[(i+1)%n].y) {
            continue;
        }

        int x = findXCord(dots[i], dots[(i+1)%n], mainDot);

        // In case dot is on the peak
        if (x == dots[i].x) {
            counter--;
        }

        if (mainDot.x < x) {
            counter++;
        }
    }

    return counter % 2 == 1; 
}

int main() {
    int n;
    dot mainDot;

    cout << "Input num of peaks" << endl;
    cin >> n;

    cout << "Input cords of peaks" << endl;
    dot* dots = new dot[n];
    for (int i = 0; i < n; ++i)
        cin >> dots[i].x >> dots[i].y;

    cout << "Input dot cords" << endl;
    cin >> mainDot.x >> mainDot.y;

    if (isInside(dots, n, mainDot))
        cout << "Dot is inside";
    else
        cout << "Dot isn't inside";

    return 0;
}