#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;

const long long mod = 1e9 + 7;

vector <vector <int>> dp;

int helper(int current, int prev) {
    if (current == 0) {
        return 1;
    }

    if (current < 0) {
        return 0;
    }

    if (dp[current][prev] != -1) {
        return dp[current][prev];
    }

    long long ret = 0;

    if (prev == 0) {
        for (int i = 1; i <= 5; i++) {
            ret = ((ret % mod) + (helper(current - 1, i) % mod)) % mod;
        }
    } else if (prev == 1) {
        ret = ((ret % mod) + (helper(current - 1, 2) % mod)) % mod;
    } else if (prev == 2) {
        ret = ((ret % mod) + (helper(current - 1, 1) % mod)) % mod;
        ret = ((ret % mod) + (helper(current - 1, 3) % mod)) % mod;
    } else if (prev == 3) {
        for (int i = 1; i <= 5; i++) {
            if (i != 3) {
                ret = ((ret % mod) + (helper(current - 1, i) % mod)) % mod;
            }      
        }
    } else if (prev == 4) {
        ret = ((ret % mod) + (helper(current - 1, 3) % mod)) % mod;
        ret = ((ret % mod) + (helper(current - 1, 5) % mod)) % mod;
    } else if (prev == 5) {
        ret = ((ret % mod) + (helper(current - 1, 1) % mod)) % mod;
    }

    dp[current][prev] = ret;

    return ret;
}

int countVowelPermutation(int n) {
    dp.resize(n + 1, vector <int> (6, -1));
    return helper(n, 0);
}

int main() {
    return 0;
}