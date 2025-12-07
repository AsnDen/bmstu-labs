#include <iostream>
#include <vector>

struct Circle {
    double r;
};

struct Rectange {
    double a;
    double b;
};

union Shape {
    Circle c;
    Rectange r;

};

int main()
{

    std::cout << "Choose a shape (1 - circle, 2 - rectangle)\n";
    unsigned short int inp{};
    std::cin >> inp;
    Shape figure;
    switch( inp ) {
        case 1:
            std::cout << "Enter a radius\n";
            std::cin >> figure.c.r;
            std::cout << "Area is " << figure.c.r * figure.c.r * 3.14 << '\n';
            break;
        case 2:
            std::cout << "Enter width and lenght\n";
            std::cin >> figure.r.a >> figure.r.b;
            std::cout << "Area is "
                      << figure.r.a * figure.r.b << '\n';
            break;

        default:
            break;
    }


    return 0;
}
