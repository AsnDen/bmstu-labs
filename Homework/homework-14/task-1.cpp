#include <iostream>
#include <string>

class Publication
{
    protected:
        std::string name{};
};

class Book : public Publication
{
    protected:
        std::string author{};
        size_t year{};

    public:
        Book( std::string new_name, std::string new_author, size_t new_year ) {
            name = new_name;
            author = new_author;
            year = new_year;
        }

        void displayInfo() {
            std::cout << "Name: " << this->name << '\n'
                      << "Author: " << this->author << '\n'
                      << "Year: " << this->year << '\n';
        }
};

int main()
{
    Book myMegaBook{"Super-book", "AsnDen", 3025};
    myMegaBook.displayInfo();
    return 0;
}
