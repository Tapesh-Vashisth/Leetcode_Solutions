#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int dp[amount + 1];
    for (auto & it: dp) {
        it = INT32_MAX;
    }

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT32_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[amount] == INT32_MAX ? -1: dp[amount];
}

int main() {
    return 0;
}