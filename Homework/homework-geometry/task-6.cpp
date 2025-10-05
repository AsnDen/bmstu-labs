#include <iostream>
#include <cmath>

using namespace std;

double defineDotPosition(double xp, double yp, double x1, double y1, double x2, double y2) {
    return (x2 - x1) * (yp - y1) - (y2 - y1) * (xp - x1);
}

double dist(double x1, double x2, double y1, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4; 
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cin >> x4 >> y4;

    double cp1 = defineDotPosition(x3, y3, x1, y1, x2, y2);
    double cp2 = defineDotPosition(x4, y4, x1, y1, x2, y2);
    double cp3 = defineDotPosition(x1, y1, x3, y3, x4, y4);
    double cp4 = defineDotPosition(x2, y2, x3, y3, x4, y4);

    bool isInsert = false;

    if ((cp1 * cp2 < 0) && (cp3 * cp4 < 0)) {
        isInsert = true;
    } 
    else if ((cp1 * cp2 == 0) && (cp3 * cp4 == 0)){
        double AB = dist(x1, y1, x2, y2);
        double AC = dist(x1, y1, x3, y3);
        double AD = dist(x1, y1, x4, y4);
        double BC = dist(x2, y2, x3, y3);
        double BD = dist(x2, y2, x4, y4);
        double CD = dist(x3, y3, x4, y4);
        
        // Checking if any dot is in the segment
        // C checking
        if ((AC + BC - AB) == 0){
            isInsert = true;
        }
        // D checking
        if ((AD + BD - AB) == 0){
            isInsert = true;
        }
        // A checking
        if ((AC + AD - CD) == 0){
            isInsert = true;
        }
        // B checking
        if ((BC + BD - CD) == 0){
            isInsert = true;
        }
    }

    if (isInsert) {
        cout << "The segments intersect";
    } 
    else {
        cout << "The segments don't intersect";
    }

    return 0;
}