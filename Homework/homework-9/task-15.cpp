#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> routes {
        "Moscow-Berlin",
        "Berlin-Paris",
        "Paris-Rome",
        "Rome-Moscow"
    };

    auto ptrRoutes = std::make_shared<std::vector<std::string>>(routes);

    auto countCity = [](std::shared_ptr<std::vector<std::string>> routesPtr, const std::string& city) {
        int count{};
        for (const auto& route : *routesPtr) {
            if (route.find(city) != std::string::npos) ++count;
        }
        return count;
    };

    auto sortByLength = [](std::shared_ptr<std::vector<std::string>> routesPtr) {
        std::sort(routesPtr->begin(), routesPtr->end(),
                  [](const std::string& a, const std::string& b) {
                      return a.length() > b.length();
                  });
    };

    auto concat = [](std::shared_ptr<std::vector<std::string>> routesPtr) {
        std::string result{};
        for (size_t i{}; i < routesPtr->size(); ++i) {
            result += (*routesPtr)[i];
            if (i != routesPtr->size() - 1) result += " -> ";
        }
        return result;
    };

    int parisCount = countCity(ptrRoutes, "Paris");
    std::cout << "Number of routes from or to Paris: " << parisCount << std::endl;

    sortByLength(ptrRoutes);

    std::cout << "Sorted routes:" << std::endl;
    for (const auto& route : *ptrRoutes) std::cout << route << "\n";

    std::string allRoutes {concat(ptrRoutes)};
    std::cout << "Final route " << allRoutes << std::endl;

    return 0;
}
