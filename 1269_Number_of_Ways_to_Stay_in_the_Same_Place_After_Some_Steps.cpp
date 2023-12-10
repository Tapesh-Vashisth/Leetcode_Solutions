#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;

int numWays(int steps, int arrLen) {
    vector <vector <int>> dp(steps + 1, vector <int> (steps, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= steps; i++) {
        for (int j = 0; j < min(arrLen, steps); j++) {
            dp[i][j] = ((dp[i - 1][j] % mod) + ((j - 1 >= 0 ? dp[i - 1][j - 1] : 0) % mod) + ((j + 1 < steps ? dp[i - 1][j + 1] : 0) % mod)) % mod;
        }
    }

    return dp[steps][0];
}

int main() {
    return 0;
}