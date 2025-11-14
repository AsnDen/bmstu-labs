#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <iomanip>
#include <algorithm>

struct dish {
    std::string name{};
    double price{};
    std::string category{};
};

/* File manipulations */

void createFile(std::string filename) {
    std::ofstream file(filename);
    file.close();
}

int deleteFile(std::string filename) {
    return std::filesystem::remove(filename) ? 0 : 201;
}

bool checkFileOpen(std::fstream& file) {
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open the file" << std::endl;
        return false;
    }

    return true;
}

int addDishesToFile(std::string filename) {

    if (!std::filesystem::exists(filename)) createFile(filename); 

    std::fstream file(filename, std::ios::app);

    if (!checkFileOpen(file)) return 200;
    
    std::string inp{};
    std::getline(std::cin, inp);
    std::cin.ignore();
    do {
        file << inp << "\n";
        std::getline(std::cin, inp);
        std::cin.ignore();
    } while (!inp.empty());

    file.close();
    
    return 0;
}

dish parseLine(std::string line) {
    dish parsedDish{};
    bool dishName {true};
    bool dishPrice {false};
    std::string temp{};
    for (char ch : line) {
        if (ch != ',') {
            temp += ch;
        } else {
            if (dishPrice) dishPrice = false, parsedDish.price = std::stod(temp);
            if (dishName) dishName = false, dishPrice = true, parsedDish.name = temp;
            temp = "";
        }
    }
    
    parsedDish.category = temp;

    return parsedDish;
}

int parseFile(std::string filename, std::vector<dish>& DishPool){
    std::fstream file("menu.txt", std::ios::in);
    DishPool.clear();

    if (!checkFileOpen(file)) return 200;

    std::string line {};
    std::getline(file, line);
    do {
        dish parsedDish = parseLine(line);
        DishPool.push_back(parsedDish);
        std::getline(file, line);
    } while (!line.empty());

    file.close();

    return 0;
}

int overwriteFile(std::string filename, std::vector<dish>& DishPool) {
    
    if (deleteFile(filename)) return 201;
    
    createFile(filename);
    
    std::fstream file(filename, std::ios::out);

    if (!checkFileOpen(file)) return 200;

    for (dish d: DishPool) {
        file << d.name << "," << d.price << ',' << d.category << std::endl;
    }


    file.close();

    return 0;
}

int addLogToFile(std::string filename, std::string message) {
    if (!std::filesystem::exists(filename)) createFile(filename); 

    std::fstream file(filename, std::ios::app);

    if (!checkFileOpen(file)) return 200;

    file << message << std::endl;
    
    file.close();

    return 0;
}

/* User commands */

void showDishInfo(dish d) {
    std::cout << std::left;
    std::cout << "----------------------" << std::endl <<
    std::setw(10) << "Name: " << d.name << std::endl <<
    std::setw(10) << "Price: " << d.price << std::endl <<
    std::setw(10) << "Category: " << d.category << std::endl;
    std::cout << std::right;
}

int findDish(std::string filename, std::vector<dish>& dishPool, std::string* dishName) {
    if (parseFile(filename, dishPool)) return 200;

    bool isDishFound {false};
    for (dish d : dishPool) {
        if (d.name == *dishName) {
            isDishFound = true;
            showDishInfo(d);
        }
    }

    if (!isDishFound) {std::cout << "There is no such dish" << std::endl; return 10;}

    return 0;
}

int sortByPrice(std::string filename, std::vector<dish>& dishPool) {
    if (parseFile(filename, dishPool)) return 200;

    size_t size = dishPool.size();

    // Bubble sorting
    for (size_t i{}; i < size - 1; i++) for (size_t j{}; j < size - 1 - i; j++) if (dishPool[j].price > dishPool[j+1].price) std::swap(dishPool[j], dishPool[j+1]);

    return overwriteFile(filename, dishPool);
}

int sortByCat(std::string filename, std::vector<dish>& dishPool) {
    if (parseFile(filename, dishPool)) return 200;

    size_t size = dishPool.size();

    // Bubble sorting
    for (size_t i{}; i < size - 1; i++) for (size_t j{}; j < size - 1 - i; j++) if (dishPool[j].category > dishPool[j+1].category) std::swap(dishPool[j], dishPool[j+1]);

    return overwriteFile(filename, dishPool);
}

int showByLowerPrice(std::string filename, std::vector<dish>& dishPool, double* maxPrice) {
    if (parseFile(filename, dishPool)) return 200;

    bool isDishFound {false};
    for (dish d: dishPool) if (d.price <= *maxPrice) {isDishFound = true; (showDishInfo(d));}

    if (!isDishFound) {std::cout << "No dishes were found" << std::endl; return 10;}

    return 0;
}

int main() {
    std::vector<dish> dishes{};
    const std::string filename {"menu.txt"};
    const std::string filelog {"output.txt"};
    const std::string menutext {
        "======================\n"
        "Chose the option (enter the number)\n"
        "1. Add dish to the menu\n"
        "2. Find dish by name\n"
        "3. Sort dishes by price\n"
        "4. Sort dishes by category\n"
        "5. Show dishes lower then certain price\n"
        "6. Delete menu\n"
        "0. Close the program"
    };

    addLogToFile(filelog, "LOG:Starting program");
    while (true) {
        std::cout << menutext << std::endl;
        short int inp {};
        std::cin >> inp;
        std::cin.ignore();
        switch (inp) {
            case 1: {
                addLogToFile(filelog, "LOG:Attempt to add dishes to a file");
                switch (addDishesToFile(filename)) {
                    case 0: addLogToFile(filelog, "LOG:Dishes were added successfully to the menu"); break;
                    case 200: addLogToFile(filelog, "ERR:Error occured while reading a file"); return -1; break;
                    default: addLogToFile(filelog, "ERR:Unexpected error occured while adding a dish"); return -1; break;
                }
                break;
            }
            case 2: {
                addLogToFile(filelog, "LOG:Attempt to find dish in a file");
                std::string* dishName {new std::string};
                std::cout << "What dish do you want to find?" << std::endl;
                std::getline(std::cin, *dishName);
                std::cin.ignore();
                switch (findDish(filename, dishes, dishName)) {
                    case 0: addLogToFile(filelog, "LOG:Dish '" + *dishName + "' was found successfully"); break;
                    case 10: addLogToFile(filelog, "LOG:Dish '" + *dishName + "' was not found"); break;
                    case 200: addLogToFile(filelog, "ERR:Error occured while reading a file"); return -1; break;
                    default: addLogToFile(filelog, "ERR:Unexpected error occured while finding a dish"); return -1; break;
                }
                delete dishName;
                dishName = nullptr;
                break;
            }
            case 3: {
                addLogToFile(filelog, "LOG:Attempt to sort dishes by price");
                switch (sortByPrice(filename, dishes)) {
                    case 0: addLogToFile(filelog, "LOG:Dishes were sorted successfully by price"); break;
                    case 200: addLogToFile(filelog, "ERR:Error occured while reading a file"); return -1; break;
                    default: addLogToFile(filelog, "ERR:Unexpected error occured while sorting a file"); return -1; break;
                }
                break;
            }
            case 4: {
                addLogToFile(filelog, "LOG:Attempt to sort dishes by category");
                switch (sortByCat(filename, dishes)) {
                    case 0: addLogToFile(filelog, "LOG:Dishes were sorted successfully by category"); break;
                    case 200: addLogToFile(filelog, "ERR:Error occured while reading a file"); return -1; break;
                    default: addLogToFile(filelog, "ERR:Unexpected error occured while sorting a file"); return -1; break;
                }
                break;
            }
            case 5: {
                addLogToFile(filelog, "LOG:Attempt to see dishes by price");
                double* maxPrice {new double};
                std::cout << "Enter the price" << std::endl;
                std::cin >> *maxPrice;
                std::cin.ignore();
                switch (showByLowerPrice(filename, dishes, maxPrice)) {
                    case 0: addLogToFile(filelog, "LOG:Dishes were shown successfully"); break;
                    case 10: addLogToFile(filelog, "LOG:There are no dishes that can be shown"); break;
                    case 200: addLogToFile(filelog, "ERR:Error occured while reading a file"); return -1; break;
                    default: addLogToFile(filelog, "ERR:Unexpected error occured while showing the dished"); return -1; break;
                }
                delete maxPrice;
                maxPrice = nullptr;
                break;
            }
            case 6: {
                addLogToFile(filelog, "LOG:Attempt to delete a file");
                switch (deleteFile(filename)) {
                    case 0: addLogToFile(filelog, "LOG:Menu was deleted successfully"); break;
                    case 201: addLogToFile(filelog, "ERR:Error occured while deleting a file"); return -1; break;
                    default: addLogToFile(filelog, "ERR:Unexpected error occured while deleting a file"); return -1; break;
                }
                break;
            }
            case 0: {
                addLogToFile(filelog, "LOG:Closing program");
                return 0;
                break;
            }
            default: {
                addLogToFile(filelog, "LOG:Unexpected command");
                std::cerr << "Invalid value. Try again" << std::endl;
                break;
            }
        }
    }
}