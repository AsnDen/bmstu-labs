#include <iostream>
#include <cmath>
#include <algorithm>

int rotate(int x1, int y1, int x2, int y2, int x3, int y3) {
    int opr = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (opr > 0) return 1;   
    if (opr < 0) return -1;              
}


bool onTheSegment(int x1, int y1, int qx, int qy, int x2, int y2) {
    return ( (x1 <= qx && qx <= x2) || (x2 <= qx && qx <= x1) ) && ( (y1 <= qy && qy <= y2) || (y2 <= qy && qy <= y1) );
}

bool crossing(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4) {
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
int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4; 
    std::cin >> x1 >> y1;
    std::cin >> x2 >> y2;
    std::cin >> x3 >> y3;
    std::cin >> x4 >> y4;

    if (crossing(x1, y1, x2, y2, x3, y3, x4, y4)) {
        std::cout << "The segments intersect";
    } 
    else {
        std::cout << "The segments don't intersect";
    }

    return 0;
}