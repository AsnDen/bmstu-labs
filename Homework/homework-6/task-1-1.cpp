#include <iostream>
#include <cstring>
#include <algorithm>

int main() {

    char str[100];
    std::cin.getline(str, 100);

    int len {int(strlen(str))};

    int mx {0};
    int index {0};
    int counter {0};
    for (int i = 0; i < len+1; i++) {
        counter++;
        if (isspace(str[i]) || str[i] == '\0') {
            if (mx < counter-1) {
                mx = counter-1;
                index = i-1;
            }
            counter = 0;
        }
    }
    
    std::pair<int, int> mm {index-mx+1,index};

    for (int i = 0; i < len; i++){
        (mm.first <= i) && (i <= mm.second) && (printf("%c", str[i]));
    }
}