#include <iostream>
#include <cmath>

using namespace std;

struct dot {
    double x,y;
};

int rotate(int x1, int y1, int x2, int y2, int dotx, int doty) {
    int opr = (x2 - x1) * (doty - y1) - (y2 - y1) * (dotx - x1);
    if (opr > 0) return 1;
    if (opr < 0) return -1;
    return 0; 
}

bool isInside(dot dots[], int n, double dotx, double doty) {
    int sign = 0;
    bool onEdge = false;

    for (int i = 0; i < n; ++i) {
        int r = rotate(dots[i].x, dots[i].y, dots[(i+1)%n].x, dots[(i+1)%n].y, dotx, doty);
        if (r == 0) onEdge = true; 
        else if (sign == 0) sign = r; 
        else if (r != 0 && r != sign) return false; 
    }

    return true; 
}

int main() {
    int n;
    double dotx, doty;

    
    cout << "Input num of peaks" << endl;
    std::cin >> n;

    cout << "Input dot cords" << endl;
    std::cin >> dotx >> doty;

    cout << "Input cords of peaks" << endl;
    dot* dots = new dot[n];
    for (int i = 0; i < n; ++i)
        std::cin >> dots[i].x >> dots[i].y;

    if (isInside(dots, n, dotx, doty))
        std::cout << "Dot is incide";
    else
        std::cout << "Dot isn't incide";

    return 0;
}