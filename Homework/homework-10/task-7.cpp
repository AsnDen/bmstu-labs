#include <iostream>
#include <fstream>
#include <string>

int main() {

    const std::string FILE_NAME{"numbers.txt"};

    std::fstream file(FILE_NAME, std::ios::in);

    if (file.fail()) {
        std::cerr << "Error while opening a file" << std::endl;
        return -1;
    }

    int sum{};
    size_t counter{};
    int num{};
    while (file >> num) {
        sum += num;
        counter++;
    }
    
    std::cout << "Sum is " << sum << std::endl;
    std::cout << "Average is " << double(sum)/counter << std::endl;

    file.close();

    return 0;
}