#include <iostream>
#include <memory>
#include <cstring>

int main() {

    const char str[] {"Haha stupid string"};
    size_t n{std::size(str)};
    std::unique_ptr<char[]> arr {std::make_unique<char[]>(100)};


    for (size_t i{}; i < n; i++) {
        arr[i] = str[i];
        std::cout << arr[i];
    }
    std::cout << std::endl;

    unsigned int vowels{};
    unsigned int consonants{};
    for (size_t i{}; i < n; i++) {
        int c {std::tolower(arr[i])};
        if (isalpha(c)) {
            (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') ? vowels++ : consonants++;
        }
    }

    std::unique_ptr<char[]> vowelsArr = std::make_unique<char[]>(vowels + 1);

    size_t ind{};
    for (size_t i{}; i < n; i++) {
        int c {std::tolower(arr[i])};
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
            vowelsArr[ind++] = arr[i];             
        }
    }

    std::cout << "Vowels: " << vowels << std::endl;
    std::cout << "Consonants: " << consonants << std::endl;

    std::cout << vowelsArr.get() << std::endl;

    return 0;
}