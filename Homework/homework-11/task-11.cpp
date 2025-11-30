#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    std::ifstream in("sensor_data.txt");
    std::vector<double> temperatures{};
    double temp{};

    while (in >> temp)
    {
        temperatures.push_back(temp);
    }
    in.close();

    auto valid_temp = [](double t)
    { return t >= -50 && t <= 50; };
    temperatures.erase(std::remove_if(temperatures.begin(),
                                      temperatures.end(),
                                      valid_temp),
                       temperatures.end());

    std::ofstream out("filtered_sensor_data.txt");
    for (double t : temperatures)
    {
        out << t << std::endl;
    }
    out.close();

    double sum = std::accumulate(temperatures.begin(), temperatures.end(), 0.0);
    double average = sum / static_cast<double>(temperatures.size());

    std::cout << "Average temperature: " << average << std::endl;
    std::cout << "Number of fileted data: " << temperatures.size() << std::endl;

    return 0;
}
