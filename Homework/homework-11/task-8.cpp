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
    std::string file_name_filtered{"filtered_products.csv"};

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

    auto expensive_filter = [](const Product &p)
    { return p.price > 5000; };

    /* Unused filters
    auto electronics_filter = [](const Product &p)
    { return p.category == "Электроника"; };
    auto in_stock_filter = [](const Product &p)
    { return p.quantity > 10; };
    */

    std::vector<Product> filtered{};
    std::copy_if(products.begin(), products.end(),
                 std::back_inserter(filtered), expensive_filter);

    std::ofstream out(file_name_filtered);
    out << "id,name,category,price,quantity\n";

    for (const auto &p : filtered)
    {
        out << p.id << "," << p.name << "," << p.category << ","
            << p.price << "," << p.quantity << "\n";
    }
    out.close();

    std::cout << "Num of filtered products: " << filtered.size() << '\n';

    return 0;
}
