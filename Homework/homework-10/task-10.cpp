#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <iomanip>

int main() {

    const std::string FILE_NAME{"power_log.txt"};
    const std::string OUTPUT_FILE_NAME{"energy_report.txt"};

    std::fstream file(FILE_NAME, std::ios::in);

    if (file.fail()) {
        std::cerr << "Error while opening a file" << std::endl;
        return -1;
    }

    std::map<std::string, std::vector<double>> machine_values {};
    std::map<std::string, size_t> machine_counter {};

    std::string line{};
    while (std::getline(file, line)) {
        std::stringstream lineStream{line};
        std::string name{};
        double value{};

        lineStream >> name >> name >> value;
        machine_values[name].push_back(value);
        machine_counter[name]++;
    }

    file.close();

    std::fstream file_out(OUTPUT_FILE_NAME, std::ios::out);

    if (file_out.fail()) {
        std::cerr << "Error while opening a file" << std::endl;
        return -1;
    }

    for (auto const& [name, values] : machine_values) {
        size_t& counter = machine_counter[name];

        double sum {std::accumulate(values.begin(), values.end(), 0.0)};
        file_out << name <<
        ": measurements = " << counter <<
        ", total = " << sum << " kWh, average = " <<
        std::setprecision(3) << sum/values.size() << " kWh"
        << std::endl;
    }
    file_out.close();

    return 0;
}