#include <iostream>
#include <cmath>

using namespace std;

struct dot {
    double x,y;
};

double defineDotPosition(dot dp, dot d1, dot d2) {
    return (d2.x - d1.x) * (dp.y - d1.y) - (d2.y - d1.y) * (dp.x - d1.x);
}

double dist(dot first, dot second) {
    double dx = first.x - second.x;
    double dy = first.y - second.y;
    return sqrt(dx*dx + dy*dy);
}


bool doPolygonsIntersect(dot figure1[], int n1, dot figure2[], int n2) {
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n2; j++) {
            
            dot d1 = figure1[i];
            dot d2 = figure1[(i+1)%n1];
            dot d3 = figure2[j];
            dot d4 = figure2[(j+1)%n2];
            
            double cp1 = defineDotPosition(d3, d1, d2);
            double cp2 = defineDotPosition(d4, d1, d2);
            double cp3 = defineDotPosition(d1, d3, d4);
            double cp4 = defineDotPosition(d2, d3, d4);

            bool isInsert = false;

            if ((cp1 * cp2 < 0) && (cp3 * cp4 < 0)) {
                isInsert = true;
            } else if ((cp1 * cp2 == 0) || (cp3 * cp4 == 0)){
                double AB = dist(d1, d2);
                double AC = dist(d1, d3);
                double AD = dist(d1, d4);
                double BC = dist(d2, d3);
                double BD = dist(d2, d4);
                double CD = dist(d3, d4);
                
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
                return true;
            }
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

    if (doPolygonsIntersect(figure1, n1, figure2, n2))
        cout << "Figures intersect" << endl;
    else
        cout << "Figures don't intersect" << endl;

    return 0;
}

