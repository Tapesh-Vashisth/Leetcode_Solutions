#include <iostream>
#include <vector>
using namespace std;

int longestPalindromeSubseq(string s) {
    int dp[s.size() + 1][s.size() + 1];

    for (int i = 0; i <= s.size(); i++) {
        for (int j = 0; j <= s.size(); j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i < s.size() + 1; i++) {
        for (int j = i; j >= 1; j--) {
            // not take
            int notTake = dp[i - 1][j];

            // take 
            int take = max((s[i - 1] == s[j - 1] ? ((i - 1) != (j - 1)) ? 2 : 1 : 0) + ((j + 1) <= (i - 1) ? dp[i - 1][j + 1] : 0), j + 1 <= i ? dp[i][j + 1]: 0);

            dp[i][j] = max(take, notTake);
        }
    }


    return dp[s.size()][1];
}

int main() {
    return 0;
}