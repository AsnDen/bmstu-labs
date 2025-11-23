#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {

    const std::string FILE_NAME{"vibration_log.txt"};
    const std::string OUTPUT_FILE_NAME{"vibration_report.txt"};

    std::fstream file(FILE_NAME, std::ios::in);

    if (file.fail()) {
        std::cerr << "Error while opening a file" << std::endl;
        return -1;
    }

    double inp{};
    std::vector<double> data{};
    
    while (file >> inp) {
        data.push_back(inp);
    }

    file.close();

    std::fstream file_out(OUTPUT_FILE_NAME, std::ios::out);

    file_out << "Number of measures " << data.size() << std::endl;
    data.erase(std::remove_if(data.begin(), data.end(), [](const double& x){return x <= 0.05;}), data.end());

    auto findAverage = [](std::vector<double>& vec){
        double sm{};
        for (double& x : vec) sm += x;
        return sm / vec.size();
    };

    auto findMax = [](std::vector<double>& vec){
        double max{vec[0]};
        for (double& x : vec) {
            if (x > max) max = x;
        }
        return max;
    };

    auto findMin = [](std::vector<double>& vec){
        double min{vec[0]};
        for (double& x : vec) {
            if (x < min) min = x;
        }
        return min;
    };

    file_out << "Filtered data: ";
    for (double& x : data) file_out << x << ' ';
    file_out << std::endl;
    file_out << "Average is " << findAverage(data) << std::endl;
    file_out << "Minimum is " << findMin(data) << std::endl;
    file_out << "Maximum is " << findMax(data) << std::endl;

    file_out.close();

    std::cout << "Analysis is done. Report is in " << OUTPUT_FILE_NAME << std::endl;

    return 0;
}