#include <iostream>
#include <cstring>
#include <algorithm>

int main() {

    char str[100];
    std::cin.getline(str, 100);
    int subLen;
    std::cin >> subLen;
    
    int len {int(strlen(str))};
    
    for (int i = 0; i <= len-subLen; i++) {
        char* sub = new char[subLen+1];
        strncpy(sub, str+i, subLen);
        sub[subLen] = '\0';

        char* temp = new char[subLen+1];
        strcpy(temp, sub);

        std::sort(temp, temp+subLen);
        auto it2 = std::unique(temp, temp+subLen);
        
        (it2 - temp == subLen) && (printf("%s\n", sub));
    }

    return 0;
}