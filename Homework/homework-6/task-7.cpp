#include <iostream>
#include <cstring>

char* RLE(char str[]) {
    char* rle {new char[100]};
    int len {int(strlen(str))};
    int rleLen {0};
    int rleStrLen {0};
    char lastChar = str[0];
    
    for (int i = 1; i < len+1; i++){
        ((++rleLen < 9) && (lastChar == str[i])) || (rle[rleStrLen++] = lastChar, rle[rleStrLen++] = rleLen + '0', rleLen = 0);
        lastChar = str[i];
    }

    rle[rleStrLen] = '\0';

    return rle;
}

int main() {

    char str[100];
    std::cin.getline(str, 100);

    char* rle = RLE(str);

    printf("%s", rle);
}