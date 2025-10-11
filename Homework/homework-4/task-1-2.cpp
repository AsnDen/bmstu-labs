#include <iostream>
#include <vector>
#include <numbers>

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
    angle = angle * std::numbers::pi / 180; 

    std::cout << "Cords are: " << a.x*std::cos(angle) + a.x*std::sin(angle) << " " << -a.y*std::sin(angle) + a.y*std::cos(angle) << std::endl;

    return 0;
}