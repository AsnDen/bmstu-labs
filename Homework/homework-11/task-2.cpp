#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

/*
* This program edits changes values in config file
*/

int main() {

    const std::string file_name {"config.txt"};
    const std::string key {"timeout="};
    const std::string new_value {"60"};
    std::fstream file{file_name, std::ios::in | std::ios::out};

    if (file.fail()) {
        std::cerr << "Error while opening a file\n";
        return -1;
    }

    // Temporary store text here
    std::vector<char> buffer{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};

    std::string file_text {buffer.begin(), buffer.end()};
    buffer.clear();

    // Find the position of a value we are going to change
    size_t pos {file_text.find(key)};
    if (pos == std::string::npos) {
        std::cerr << "Incorrect values in file\n";
        return -1;
    }

    size_t valueStart {pos + key.length()};
    size_t valueEnd {file_text.find('\n', valueStart)};

    file_text.replace(valueStart, valueEnd - valueStart, new_value);

    file.seekp(0, std::ios::beg);
    file.write(file_text.c_str(), static_cast<std::streamsize>(file_text.size()));

    file.flush();
    file.close();

    return 0;
}
