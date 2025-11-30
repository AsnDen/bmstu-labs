#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {

    const std::string FILE_NAME {"book.txt"};
    const std::string FILE_NAME_RES {"result.txt"};
    const std::string WORD {"hero"};

    std::vector<std::pair<int, int>> data{};
    
    std::fstream file{FILE_NAME, std::ios::in};

    if (file.fail()) {
        std::cerr << "Error while opening a file" << std::endl;
        return -1;
    }

    std::string line{};
    size_t lineNum{};
    while (std::getline(file, line)) {
        lineNum++;

        size_t pos {line.find(WORD)};
        while (pos != std::string::npos) {
            data.push_back({lineNum, pos});
            pos = line.find(WORD, pos + WORD.length());
        }
    }

    file.close();

    std::fstream file_res{FILE_NAME_RES, std::ios::out};

    if (file_res.fail()) {
        std::cerr << "Error while opening a file" << std::endl;
        return -1;
    }

    for (auto v : data) {
        file_res << v.first << ' ' << v.second << ' ' << WORD << '\n';
    }

    file_res.close();

    return 0;
}
