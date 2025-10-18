#include <iostream>
#include <cstring>

int main() {

    char str1[100];
    std::cin.getline(str1, 100);
    
    char str2[100];
    std::cin.getline(str2, 100);

    int len1 {int(strlen(str1))};
    int len2 {int(strlen(str2))};
    bool all {true};
    for (int i = 1; i < len2; i++) {
        bool any {false};
        for (int j = 0; j < len1; j++) if (str2[i] == str1[j]) {any = true; break;}
        if (!any) {all = false; break;}
    }

    all ? printf("Yes") : printf("No");

    return 0;
}