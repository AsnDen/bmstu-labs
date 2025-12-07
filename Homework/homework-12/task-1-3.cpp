#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Book {
    size_t year{};
    std::string name{};
    std::string author{};
    std::string genre{};
};

struct Library {
    std::vector<Book> vec{};
    size_t num_of_books{};
};

void showMenu();
void showBook( const Book &book );
void addBook( Library &lib );
void deleteBook( Library &lib );
void findBook( const Library &lib );
void showAllBooks( const Library &lib );

void showMenu()
{
    std::cout << "--------------------\n"
              << "Choose an option:\n"
                 "1. Add a book\n"
                 "2. Delete a book\n"
                 "3. Find book\n"
                 "4. Show all books\n"
                 "5. Exit\n";
}

void showBook( const Book &book )
{
    std::cout << "-------------------\n"
              << "Name: " << book.name << '\n'
              << "Year: " << book.year << '\n'
              << "Author: " << book.author << '\n'
              << "Genre: " << book.genre << '\n';
}

void addBook( Library &lib )
{
    Book new_book{};
    std::cout << "Enter book's name, year of publish, author and genre\n";
    std::cin >> new_book.name >> new_book.year >> new_book.author >> new_book.genre;
    lib.num_of_books += 1;
    lib.vec.push_back( new_book );
}

void deleteBook( Library &lib )
{
    std::cout << "Enter book's name\n";
    std::string name{};
    std::cin >> name;

    std::vector<Book> &vec = lib.vec;
    bool isDeleted{false};
    vec.erase( std::remove_if( vec.begin(), vec.end(),
    [&isDeleted, &name]( Book book ) {
        if( !isDeleted ) {
            if( book.name == name ) {
                isDeleted = true;
                return true;
            }
        }
        return false;
    } ), vec.end() );
}

void findBook( const Library &lib )
{
    std::cout << "Enter book's author\n";
    std::string author{};
    std::cin >> author;

    for( Book book : lib.vec ) {
        if( book.author == author ) {
            showBook( book );
        }
    }
}

void showAllBooks( const Library &lib )
{
    for( Book book : lib.vec ) {
        showBook( book );
    }
}

int main()
{
    Library lib{};
    bool programWorking {true};
    while( programWorking ) {
        showMenu();
        short unsigned int inp{};
        std::cin >> inp;
        switch( inp ) {
            case 1:
                addBook( lib );
                break;
            case 2:
                deleteBook( lib );
                break;
            case 3:
                findBook( lib );
                break;
            case 4:
                showAllBooks( lib );
                break;
            case 5:
                programWorking = false;
                break;

            default:
                break;
        }

        return 0;
    }
}
