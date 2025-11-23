#include <iostream>
#include <fstream>
#include <string>

int main() {

    const std::string FILE_NAME{"output.txt"};

    std::fstream file(FILE_NAME, std::ios::out);

    if (file.fail()) {
        std::cerr << "Error while creating a file" << std::endl;
        return -1;
    }

    std::string line{};

    std::cout << "Enter some lines. At end enter empty line" << std::endl;

    std::getline(std::cin, line);
    do {
        file << line << std::endl;
        std::getline(std::cin, line);
    } while (!line.empty());

    file.close();

    std::cout << "Data is in " << FILE_NAME << " file" << std::endl;

    return 0;
}