#include <iostream>

union Variant {
    int i;
    double d;
    char c;
};

int main()
{
    std::cout << "Choose a type (i - int, d - double, c - char)\n";
    char type{};
    std::cin >> type;
    std::cout << "Enter a value\n";
    Variant var;
    switch( type ) {
        case 'i':
            std::cin >> var.i;
            std::cout << var.i;
            break;
        case 'd':
            std::cin >> var.d;
            std::cout << var.d;
            break;
        case 'c':
            std::cin >> var.c;
            std::cout << var.c;
            break;

        default:
            break;
    }
    return 0;
}
