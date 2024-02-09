#include <iostream>
#include <vector>
using namespace std;


int helper(vector <int> & arr, int k, int left, vector <int> & dp) {
    if (left >= arr.size()) {
        return 0;
    }

    if (dp[left] != -1) {
        return dp[left];
    }

    int mx = 0;
    int ret = 0;
    for (int i = 0; i < k && left + i < arr.size(); i++) {
        mx = max(mx, arr[left + i]);

        ret = max(ret, mx * (i + 1) + helper(arr, k, left + i + 1, dp));
    }

    dp[left] = ret;

    return ret;
}

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    vector <int> dp(arr.size(), -1);

    return helper(arr, k, 0, dp);
}

int main() {
    return 0;
}