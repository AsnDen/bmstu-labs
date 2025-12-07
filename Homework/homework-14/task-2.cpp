#include <iostream>
#include <stdexcept>

class Shape
{
    protected:
        long double lenght{};
};

class Rectangle : public Shape
{
    protected:
        long double width{};

    public:
        Rectangle( long double l, long double w ) {
            if( l <= 0 ) {
                throw std::invalid_argument( "Length can't be negative" );
            }
            if( w <= 0 ) {
                throw std::invalid_argument( "Width can't be negative" );
            }

            lenght = l;
            width = w;
        }

        long double calculateArea() {
            return lenght * width;
        }

        long double calculatePerimeter() {
            return ( lenght + width ) * 2;
        }

        void displayInfo() {
            std::cout << "Width: " << width << '\n'
                      << "Lenght: " << lenght << '\n'
                      << "Area: " << calculateArea() << '\n'
                      << "Perimeter: " << calculatePerimeter() << '\n';
        }

};

int main()
{
    Rectangle mySuperRectange{4.3, 3};
    mySuperRectange.displayInfo();
    return 0;
}
