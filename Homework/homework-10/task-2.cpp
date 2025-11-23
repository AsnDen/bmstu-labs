#include <iostream>
#include <fstream>
#include <string>

int main() {

    const std::string FILE_NAME{"data.txt"};

    std::fstream file(FILE_NAME, std::ios::in);

    if (file.fail()) {
        std::cerr << "Error while opening a file" << std::endl;
        return -1;
    }

    std::string line{};
    int counter{};

    while (std::getline(file, line)) counter++;

    std::cout << counter << std::endl;
    
    file.close();

    return 0;
}