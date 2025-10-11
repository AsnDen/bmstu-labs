#include <iostream>
#include <vector>
#include <numbers>
#include <cmath>

struct dot{
    double x,y;
};

int main() {
    dot a;

    std::cout << "Input dot coordinates" << std::endl;
    std::cin >> a.x >> a.y;

    std::cout << "Input the angle" << std::endl;
    double angle;
    std::cin >> angle;
    angle = angle * 3.14159265358979323846 / 180; 

    std::cout << "Cords are: " << a.x*std::cos(angle) + a.y*std::sin(angle) << " " << -a.x*std::sin(angle) + a.y*std::cos(angle) << std::endl;

    return 0;
}