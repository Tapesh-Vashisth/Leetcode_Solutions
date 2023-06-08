#include <iostream>
#include <vector>
using namespace std;

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    vector <int> dp(arr.size() + 1, 0);

    vector <int> prefixSum = {0};

    int hold = 0;
    for (auto it: arr) {
        hold += it;
        prefixSum.push_back(hold);
    }

    for (int i = 1; i <= arr.size(); i++) {
        int hold = 0;
        for (int j = i - 1; j >= 0 && j >= i - k; j--) {
            hold = max(hold, dp[j] + prefixSum[i] - prefixSum[j]);
        }
        dp[i] = hold;
    }

    return dp[dp.size() - 1];
}

int main() {
    return 0;
}