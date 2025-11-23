#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>

int main() {

    const std::string FILE_NAME{"temperature_data.txt"};
    const std::string OUTPUT_FILE_NAME{"report.txt"};

    std::map<std::string, std::vector<double>> m {};

    std::fstream file(FILE_NAME, std::ios::in);

    if (file.fail()) {
        std::cerr << "Error while opening a file" << std::endl;
        return -1;
    }

    std::string line{};
    while (std::getline(file, line)) {
        std::stringstream lineStream{line};
        std::string name{};
        double value{};
        
        lineStream >> name >> value;
        m[name].push_back(value);
    }

    file.close();

    std::fstream file_out(OUTPUT_FILE_NAME, std::ios::out);

    if (file_out.fail()) {
        std::cerr << "Error while opening a file" << std::endl;
        return -1;
    }

    for (auto const& [name, vec] : m) {
        auto min {std::min_element(vec.begin(), vec.end())};
        auto max {std::max_element(vec.begin(), vec.end())};
        double sum {std::accumulate(vec.begin(), vec.end(), 0.0)};
        file_out << name << ": min = " << *min << ", max = " << *max << ", avg = " << sum/vec.size() << std::endl;
    }

    file_out.close();

    return 0;
}