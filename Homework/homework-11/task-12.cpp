#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

int main()
{
    std::vector<int> data(100000000, 1234);

    auto measure_time = [](auto func)
    {
        auto start = std::chrono::steady_clock::now();
        func();
        auto end = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    };

    auto time1 = measure_time([&]()
                              {
        std::ofstream file1("file1.bin", std::ios::binary);
        for (int num : data) {
            file1.write(reinterpret_cast<char*>(&num), sizeof(num));
        }
        file1.close(); });

    auto time2 = measure_time([&]()
                              {
        std::ofstream file2("file2.bin", std::ios::binary);
        file2.write(reinterpret_cast<char*>(data.data()),
                    static_cast<std::streamsize>(data.size() * sizeof(int)));
        file2.close(); });

    std::cout << "Revord by one: " << time1 << '\n';
    std::cout << "Record all at once: " << time2 << '\n';

    return 0;
}
