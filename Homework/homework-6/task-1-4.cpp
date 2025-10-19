#include <iostream>
#include <cstring>
#include <algorithm>

int main() {

    char str1[100];
    std::cin.getline(str1, 100);

    char str2[100];
    std::cin.getline(str2, 100);
    
    int len1 {int(strlen(str1))};
    std::sort(str1, str1+len1);
    auto it1 = std::unique(str1, str1+len1+1);

    int len2 {int(strlen(str2))};
    std::sort(str2, str2+len2);
    auto it2 = std::unique(str2, str2+len2+1);
    
    (strcmp(str1, str2)) ? printf("Strings are not panagrams") : printf("Strings are pamagrams");

    return 0;
}