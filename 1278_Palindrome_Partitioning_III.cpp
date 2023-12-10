#include <iostream>
#include <vector>
using namespace std;

int count(string & s, int start, int end) {
    int ret = 0;
    while (start < end) {
        if (s[start] != s[end]) {
            ret++;
        } 

        start++;
        end--;
    }

    return ret;
}

int palindromePartition(string s, int k) {
    vector <vector <int>> dp(k + 1, vector <int> (s.size() + 1, -1));
    dp[0][0] = 0;

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= s.size(); j++) {
            int mn = INT32_MAX;
            for (int a = j - 1; a >= 0; a--) {
                if (dp[i - 1][a] != -1) {
                    mn = min(mn, dp[i - 1][a] + count(s, a, j - 1));
                }
            }

            dp[i][j] = mn == INT32_MAX ? -1: mn;
        }
    }

    return dp[k][s.size()];
}

int main() {
    return 0;
}