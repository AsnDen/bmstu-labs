#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

int main()
{
    std::string file_name{"products.csv"};
    std::ofstream file(file_name);

    file << "id,name,category,price,quantity\n";

    std::string categories[] = {"Electronics", "Accessories", "Clothing", "Books", "Sports"};
    std::string products[] = {"Laptop", "Mouse", "Phone", "Headphones", "Keyboard",
                              "T-shirt", "Book", "Ball", "Watch", "Backpack"};

    srand(static_cast<unsigned int>(time(0)));

    for (size_t i{}; i <= 20; i++)
    {
        std::string name{products[rand() % 10]};
        std::string category{categories[rand() % 5]};
        double price{100.0 + rand() % 9900};
        int quantity{1 + rand() % 100};

        file << i << "," << name << "," << category << "," << price << "," << quantity << "\n";
    }

    file.close();
    return 0;
}
