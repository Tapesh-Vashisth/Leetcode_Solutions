#include <iostream>
#include <vector>
using namespace std;

bool check(string & s, int start, int end) {
    while (start < end) { 
        if (s[start] != s[end]) {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

bool checkPartitioning(string s) {
    vector <vector <bool>> dp(4, vector <bool> (s.size() + 1, false));

    dp[0][0] = true;

    for (int i = 1; i < dp.size(); i++) {
        for (int j = 1; j <= s.size(); j++) {
            int put = false;
            for (int k = j - 1; k >= 0; k--) {
                if (dp[i - 1][k]) {
                    put = put || (check(s, k, j - 1));
                }
            }

            dp[i][j] = put;
        }
    }

    return dp[3][s.size()];
}

int main() {
    return 0;
}