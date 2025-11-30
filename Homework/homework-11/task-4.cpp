#include <iostream>
#include <fstream>
#include <string>

int main()
{

    std::string file_name{"numbers.bin"};
    int numbers[]{15, 23, 7, 42, 18, 91, 3, 56, 77, 10};

    std::fstream file_write{file_name, std::ios::out | std::ios::binary};

    if (file_write.fail())
    {
        std::cerr << "Error while opening a file\n";
        return -1;
    }

    file_write.write(reinterpret_cast<char *>(numbers), sizeof(numbers));
    file_write.close();

    std::fstream file{file_name, std::ios::in | std::ios::binary};

    if (file.fail())
    {
        std::cerr << "Error while opening a file\n";
        return -1;
    }

    file.seekg(0, std::ios::end);
    size_t file_size{static_cast<size_t>(file.tellg())};
    file.seekg(0, std::ios::beg);

    int buff[std::size(numbers)];

    file.read(reinterpret_cast<char *>(buff), sizeof(buff));

    file.close();

    int sum{0};

    for (int num : buff)
    {
        sum += num;
    }

    std::cout << file_size << ' ' << sum << '\n';

    return 0;
}
