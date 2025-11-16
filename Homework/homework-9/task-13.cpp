#include <iostream>
#include <memory>
#include <vector>
#include <string>

int main() {
    std::unique_ptr<std::string> part1 = std::make_unique<std::string>("Sensor data:");
    std::unique_ptr<std::string> part2 = std::make_unique<std::string>("Voltage stable.");
    std::unique_ptr<std::string> part3 = std::make_unique<std::string>("System nominal.");

    std::vector<std::unique_ptr<std::string>> reportParts{};

    reportParts.push_back(std::move(part1));
    reportParts.push_back(std::move(part2));
    reportParts.push_back(std::move(part3));

    auto concatParts = [&reportParts]() {
        std::string result;
        for (const auto& p : reportParts) {
            if (!result.empty()) result += "\n";
            result += *p;
        }
        return result;
    };

    std::string reportText = concatParts();

    auto countWord = [](const std::string& text, const std::string& word) {
        size_t count = 0;
        size_t pos = 0;
        while ((pos = text.find(word, pos)) != std::string::npos) {
            ++count;
            pos += word.size();
        }
        return count;
    };

    size_t dataCount = countWord(reportText, "data");

    
    std::cout << "Report:\n" << reportText << std::endl;
    std::cout << "Word \"data\" is shown " << dataCount << " times" << std::endl;
    
    return 0;
}