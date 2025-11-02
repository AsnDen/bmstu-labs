#include <iostream>

const char* findSubstring(const char* text, const char* word) {
    
    while (*text != '\0') {

        if (*word == *text) {
            const char* tryW = word;
            const char* tryT = text;
            while (*tryW != '\0') {
                if (*tryW != *tryT) break;
                tryW++;
                tryT++;
            }
            if (*tryW == '\0') return text;
        }
        text++;
    }
    return nullptr;
}

int main() {

    char text[] {"Stupid text"};
    char word[] {"id"};
    
    const char* ans = findSubstring(text, word);

    return 0;
}