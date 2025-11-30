#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

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

    int totalQuantity{0};
    double totalValue{0.0};
    double maxPrice{products[0].price};
    double minPrice{products[0].price};
    std::string expensiveProduct{}, cheapProduct{};

    for (const auto &p : products)
    {
        std::cout << p.id << " " << p.name << " " << p.category
                  << " " << p.price << " " << p.quantity << '\n';

        totalQuantity += p.quantity;
        totalValue += p.price * p.quantity;

        if (p.price > maxPrice)
        {
            maxPrice = p.price;
            expensiveProduct = p.name;
        }
        if (p.price < minPrice)
        {
            minPrice = p.price;
            cheapProduct = p.name;
        }
    }

    std::cout << "Total num of products: " << totalQuantity << '\n';
    std::cout << "Total price: " << totalValue << '\n';
    std::cout << "The most expensive: " << expensiveProduct
              << " (" << maxPrice << ")" << '\n';
    std::cout << "The cheapests" << cheapProduct
              << " (" << minPrice << ")" << '\n';

    return 0;
}
