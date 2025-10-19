#include <iostream>
#include <cstring>

int main() {

    char str[100];
    std::cin.getline(str, 100);
    char remover[100];
    std::cin.getline(remover, 100);
    char replacer[100];
    std::cin.getline(replacer, 100);
    char ans[200];
    int index {0};

    int lenStr {int(strlen(str))};
    int lenRem {int(strlen(remover))};
    int lenRep {int(strlen(replacer))};
    
    for (int i = 0; i < lenStr;) {
        if (strncmp(&str[i], remover, lenRem) == 0) {
            strcpy(&ans[index], replacer);
            index += lenRep;
            i += lenRem;
        } else {
            ans[index++] = str[i++];
        }
    }
    ans[index] = '\0';

    printf("%s", ans);

    return 0;
}