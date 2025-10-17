#include <iostream>
#include <cstring>

int main() {

    const int WORDS {10};
    const int LETTERS {50};

    char words[WORDS][LETTERS];
    
    printf("Input 10 words\n");

    int counter {0};
    int counterSame {0};
    int mn {LETTERS + 1};

    for (int i = 0; i < WORDS; i++) {
        std::cin >> words[i];
        int len = strlen(words[i]);

        for (int j = 0; j < len; j++) {
            words[i][j] = tolower(words[i][j]);
        }
        if (words[i][0] == 'a') counter++;
        if (words[i][0] == words[i][len-1]) counterSame++;
        if (len < mn) mn = len;
    }
    
    int counterLast {0};
    for (int i = 0; i < strlen(words[WORDS-1]); i++) {
        if (words[WORDS-1][i] == 'a') counterLast++;
    }

    for (int i = 0; i < WORDS; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
    
    printf("%d words start with 'a'. %d is minumum length of word. %d letters 'a' in the last word. %d words have the same 1st and last characters\n",
        counter, mn, counterLast, counterSame);
    
    for (int word = 0; word < WORDS; word++) {
        int len = strlen(words[word]);

        for (int ch = 0; ch < len; ch++) {
            for (int newWord = word+1; newWord < WORDS; newWord++) {
                char tm[2] {words[word][ch], '\0'};
                if (newWord != word) {
                    if (std::strstr(words[newWord], tm) != nullptr) {
                        printf("The min substring is '%c'\n", words[word][ch]);
                        return 0;
                    }
                }
            }
        }
    }

    printf("There is no substring to find.");

    return 0;
}