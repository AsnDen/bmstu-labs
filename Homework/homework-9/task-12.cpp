#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>


int main() {
    std::vector<std::string> logs = {
        "INFO: Start",
        "ERROR: Disk failure",
        "WARNING: Low memory",
        "ERROR: Disk failure",
        "INFO: Stop"
    };

    auto pLogs = std::make_shared<std::vector<std::string>>(logs);

    std::vector<std::string> errors;

    auto isError = [](const std::string& msg) {
        return msg.find("ERROR") != std::string::npos;
    };

    std::copy_if(pLogs->begin(), pLogs->end(), std::back_inserter(errors), isError);

    std::sort(errors.begin(), errors.end());
    errors.erase(std::unique(errors.begin(), errors.end()), errors.end());

    std::cout << "Original logs:" << std::endl;
    for (const auto& msg : *pLogs) std::cout << msg << std::endl;

    std::cout << "Unique errors:" << std::endl;
    for (const auto& err : errors) std::cout << err << std::endl;

    return 0;
}
