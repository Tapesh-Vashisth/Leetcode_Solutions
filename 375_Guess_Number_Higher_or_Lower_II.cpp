#include <iostream>
#include <vector>
using namespace std;

int helper(int low, int high, vector <vector <int>> & dp) {
    if (low >= high) {
        return 0;
    }

    if (dp[low][high] != -1) {
        return dp[low][high];
    }

    int ret = INT32_MAX;
    for (int i = low; i <= high; i++) {
        int hold = max(helper(low, i - 1, dp) + (i != low ? i: 0), helper(i + 1, high, dp) + (i != high ? i : 0));
        ret = min(ret, hold);
    }


    dp[low][high] = ret;

    return ret;
}

int getMoneyAmount(int n) {
    vector <vector <int>> dp(n + 1, vector <int> (n + 1, -1));

    return helper(1, n, dp);
}

int main() {
    return 0;
}