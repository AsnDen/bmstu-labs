#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

struct Product
{
    int id{};
    std::string name{};
    std::string category{};
    double price{};
    int quantity{};
};

int main()
{
    std::vector<Product> products{};

    std::string file_name{"products.csv"};
    std::string file_name_sorted{"sorted_products.csv"};

    std::ifstream file(file_name);

    if (file.fail())
    {
        std::cerr << "Error while opening a file\n";
        return -1;
    }

    std::string line{};

    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss{line};
        std::string token{};
        Product p{};

        std::getline(ss, token, ',');
        p.id = std::stoi(token);
        std::getline(ss, p.name, ',');
        std::getline(ss, p.category, ',');
        std::getline(ss, token, ',');
        p.price = std::stod(token);
        std::getline(ss, token, ',');
        p.quantity = std::stoi(token);

        products.push_back(p);
    }
    file.close();

    int choice{};
    std::cout << "Sort type:\n"
              << "1 - price (to up)\n"
              << "2 - price (to down)\n"
              << "3 - name\n"
              << "4 - quantity\n";
    std::cin >> choice;

    auto price_asc = [](const Product &a, const Product &b)
    { return a.price < b.price; };
    auto price_desc = [](const Product &a, const Product &b)
    { return a.price > b.price; };
    auto name_asc = [](const Product &a, const Product &b)
    { return a.name < b.name; };
    auto quantity_desc = [](const Product &a, const Product &b)
    { return a.quantity > b.quantity; };

    switch (choice)
    {
    case 1:
        std::sort(products.begin(), products.end(), price_asc);
        break;
    case 2:
        std::sort(products.begin(), products.end(), price_desc);
        break;
    case 3:
        std::sort(products.begin(), products.end(), name_asc);
        break;
    case 4:
        std::sort(products.begin(), products.end(), quantity_desc);
        break;
    }

    std::ofstream out(file_name_sorted);
    out << "id,name,category,price,quantity\n";

    for (const auto &p : products)
    {
        out << p.id << "," << p.name
            << "," << p.category << ","
            << p.price << "," << p.quantity << '\n';
    }
    out.close();

    return 0;
}
