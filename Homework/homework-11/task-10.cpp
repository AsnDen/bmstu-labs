#include <iostream>
#include <fstream>
#include <string>

void createConfig()
{
    std::ofstream file("config.json");
    file << "{\n"
         << " \"app_name\": \"My Application\",\n"
         << " \"version\": \"1.0.0\",\n"
         << " \"settings\": {\n"
         << " \"max_connections\": 100,\n"
         << " \"timeout\": 30,\n"
         << " \"debug_mode\": true\n"
         << " },\n"
         << " \"database\": {\n"
         << " \"host\": \"localhost\",\n"
         << " \"port\": 5432,\n"
         << " \"username\": \"admin\"\n"
         << " }\n"
         << "}";
    file.close();
    std::cout << "Config file was created\n";
}

void readConfig()
{
    std::ifstream file("config.json");
    std::string line{};
    while (std::getline(file, line))
    {
        std::cout << line << '\n';
    }
    file.close();
}

void updateConfig()
{
    std::ifstream in("config.json");
    std::string content;
    std::string line;

    while (std::getline(in, line))
    {
        if (line.find("\"timeout\"") != std::string::npos)
        {
            line = " \"timeout\": 60,";
        }
        content += line + "\n";
    }
    in.close();

    std::ofstream out("config.json");
    out << content;
    out.close();
    std::cout << "Config was updated\n";
}

int main()
{
    createConfig();
    readConfig();
    updateConfig();
    readConfig();

    return 0;
}
