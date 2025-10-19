#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

int main() {

    char str1[100];
    std::cin.getline(str1, 100);
    int len1 {int(strlen(str1))};

    char str2[100];
    std::cin.getline(str2, 100);
    int len2 {int(strlen(str2))};
    
    std::vector<std::vector<int>> dp(len1+1, std::vector<int>(len2+1, 0));

    for (int i = 1; i < len1+1; i++) {
        for (int j = 1; j < len2+1; j++) {
            (str1[i-1] == str2[j-1]) && (dp[i][j] = dp[i-1][j-1] + 1);
        }
    }

    std::pair<int, int> mm {-1, -1};
    int mx = 0;
    for (int i = 1; i < len1+1; i++) {
        for (int j = 1; j < len2+1; j++) (mx < dp[i][j]) && (mm.first = i-1, mm.second = j-1, mx = dp[i][j]);
    }

    char* ans {new char[100]};

    int index {0};
    while (mm.first >= 0 && mm.second >= 0 && str1[mm.first] == str2[mm.second]) {
        ans[index++] = str1[mm.first];
        mm.first--;
        mm.second--;
    }

    ans[index] = '\0';

    std::reverse(ans, ans + index);

    printf("%s", ans);

}