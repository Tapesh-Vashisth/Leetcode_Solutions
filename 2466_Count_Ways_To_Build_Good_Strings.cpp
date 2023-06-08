#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;

int countGoodStrings(int low, int high, int zero, int one) {
    vector <int> dp(high + 1, 0);
    long long ans = 0;
    dp[0] = 1;
    for (int i = 1; i <= high; i++) {
        dp[i] = (i - one < 0 ? 0 : dp[i - one]) + (i - zero < 0 ? 0 : dp[i - zero]);
        if (i >= low && i <= high) {
            ans = ((ans % mod) + (dp[i] % mod)) % mod;
        }
    }

    return ans;
}

int main() {
    return 0;
}