#include <iostream>
#include <vector>
using namespace std;

vector <vector <int>> dp;

int helper(string & s, int left, int right) {
    if (left == right) {
        return 1;
    } else if (left > right) {
        return 0;
    }

    if (dp[left][right] != -1) {
        return dp[left][right];
    }

    int hold = INT32_MAX;

    hold = min(hold, 1 + helper(s, left + 1, right));
    for (int i = left + 1; i <= right; i++) {
        if (s[i] == s[left]) {
            hold = min(hold, helper(s, left + 1, i - 1) + helper(s, i, right));
        }
    }

    dp[left][right] = hold;

    return hold;
}

int strangePrinter(string s) {
    dp = vector <vector <int>> (s.size(), vector <int> (s.size(), -1));

    return helper(s, 0, s.size() - 1);
}


int main() {
    return 0;
}