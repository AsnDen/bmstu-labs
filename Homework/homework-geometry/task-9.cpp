#include <iostream>
#include <algorithm>

using namespace std;

struct dot {
    double x,y;
};

int rotate(int x1, int y1, int x2, int y2, int x3, int y3) {
    int opr = (x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1);
    if (opr > 0) return 1;
    if (opr < 0) return -1;
    return 0;
}

bool onTheSegment(int x1, int y1, int qx, int qy, int x2, int y2) {
    return (qx >= std::min(x1,x2) && qx <= std::max(x1,x2)) &&
           (qy >= std::min(y1,y2) && qy <= std::max(y1,y2));
}

bool isInside(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4) {
    int o1 = rotate(x1,y1, x2,y2, x3,y3);
    int o2 = rotate(x1,y1, x2,y2, x4,y4);
    int o3 = rotate(x3,y3, x4,y4, x1,y1);
    int o4 = rotate(x3,y3, x4,y4, x2,y2);

    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && onTheSegment(x1,y1, x3,y3, x2,y2)) return true;
    if (o2 == 0 && onTheSegment(x1,y1, x4,y4, x2,y2)) return true;
    if (o3 == 0 && onTheSegment(x3,y3, x1,y1, x4,y4)) return true;
    if (o4 == 0 && onTheSegment(x3,y3, x2,y2, x4,y4)) return true;

    return false;
}

bool polygonsIntersect(dot poly1[], int n1, dot poly2[], int n2) {
    for (int i = 0; i < n1; ++i) {
        int x1 = poly1[i].x, y1 = poly1[i].y;
        int x2 = poly1[(i+1)%n1].x, y2 = poly1[(i+1)%n1].y;
        for (int j = 0; j < n2; ++j) {
            int x3 = poly2[j].x, y3 = poly2[j].y;
            int x4 = poly2[(j+1)%n2].x, y4 = poly2[(j+1)%n2].y;
            if (isInside(x1,y1,x2,y2,x3,y3,x4,y4)) return true;
        }
    }
    return false;
}

int main() {
    int n1, n2;

    cout << "Input num of peaks of first figure" << endl;
    cin >> n1;

    cout << "Input cords of peaks" << endl;
    dot* figure1 = new dot[n1];
    for (int i = 0; i < n1; ++i) {
        cin >> figure1[i].x >> figure1[i].y;
    }

    cout << "Input num of peaks of second figure" << endl;
    cin >> n2;

    cout << "Input cords of peaks" << endl;
    dot* figure2 = new dot[n2];
    for (int i = 0; i < n2; ++i) {
        cin >> figure2[i].x >> figure2[i].y;
    }

    if (polygonsIntersect(figure1, n1, figure2, n2))
        std::cout << "Многоугольники пересекаются\n";
    else
        std::cout << "Многоугольники не пересекаются\n";

    return 0;
}