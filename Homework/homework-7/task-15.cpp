#include <iostream>
#include <vector>
#include <string>

struct Command {
    std::string name;
    int value;
};

void parseCommand(const char* input, std::vector<Command>& buffer) {

    bool newCommand = true;
    bool newValue = false;
    std::string name;
    std::string val;
    while (*input != '\0') {
        if (newCommand) {
            if (*input == 'F') name = "FORWARD";
            if (*input == 'T') name = "TURN";
            if (*input == 'S') name = "STOP";
            newCommand = false;
        }
        
        if (*input == ' ') newValue = true;
        
        if (newValue) {
            val += *input;
        }
        
        input++;
    }

    buffer.push_back({name, !val.empty() ? std::stoi(val) : 0});

}


int main() {

    std::vector<Command> buffer;
    parseCommand("FORWARD 10", buffer);
    parseCommand("TURN 90", buffer);
    parseCommand("STOP", buffer);

    for (Command command : buffer) {
        std::cout << "Command: " << command.name << ", Value: " << command.value << std::endl;
    }

    return 0;
}