#include <iostream>
#include <fstream>
#include <string>

int main() {

    const std::string FILE_NAME1{"file1.txt"};
    const std::string FILE_NAME2{"file2.txt"};

    std::fstream file1(FILE_NAME1, std::ios::in);
    std::fstream file2(FILE_NAME2, std::ios::in);

    if (file1.fail() || file2.fail()) {
        std::cerr << "Error while opening a file" << std::endl;
        return -1;
    }


    std::string line1{}, line2{};
    while (std::getline(file1, line1)) {
        if (!std::getline(file2, line2)) {
            std::cout << "Files are not equal" << std::endl;
            return 0;
        }
        if (line1 != line2) {
            std::cout << "Files are not equal" << std::endl;
            return 0;
        }
    }

    if (std::getline(file2, line2)) {
            std::cout << "Files are not equal" << std::endl;
            return 0;
    }

    file1.close();
    file2.close();

    std::cout << "Files are equal" << std::endl;

    return 0;
}