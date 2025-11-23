#include <iostream>
#include <fstream>
#include <string>

int main() {

    const std::string FILE_NAME{"source.txt"};
    const std::string NEW_FILE_NAME{"copy.txt"};

    std::fstream file(FILE_NAME, std::ios::in);
    std::fstream newFile(NEW_FILE_NAME, std::ios::out);

    if (file.fail()) {
        std::cerr << "Error while opening file" << std::endl;
        return -1;
    }

    if (newFile.fail()) {
        std::cerr << "Error while creating a file" << std::endl;
        return -1;
    }

    std::string line{};
    int counter{};
    while (std::getline(file, line)) {
        newFile << line << std::endl;
        counter++;
    }

    std::cout << "File is successfully copied" << std::endl;
    std::cout << "Number of lines is " << counter << std::endl;

    file.close();
    newFile.close();

    return 0;
}