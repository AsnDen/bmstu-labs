#include <iostream>
#include <sstream>
#include <string>

union Time {
    int y;
    int mo;
    int d;
    int h;
    int m;
    int s;
};


int main()
{
    Time time;
    std::stringstream ss;

    std::cout << "Enter a year ";
    std::cin >> time.y;
    ss << time.y << '-';

    std::cout << "Enter a month ";
    std::cin >> time.mo;
    ss << time.mo << '-';

    std::cout << "Enter a day ";
    std::cin >> time.d;
    ss << time.d << ' ';

    std::cout << "Enter a hour ";
    std::cin >> time.h;
    ss << time.h << ':';

    std::cout << "Enter a minute ";
    std::cin >> time.m;
    ss << time.m << ':';

    std::cout << "Enter a second ";
    std::cin >> time.s;
    ss << time.s << '\n';

    std::cout << ss.str();
    return 0;
}
