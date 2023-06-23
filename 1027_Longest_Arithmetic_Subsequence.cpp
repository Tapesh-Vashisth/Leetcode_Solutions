#include <iostream>
#include <vector>
using namespace std;

int longestArithSeqLength(vector<int>& nums) {
    vector <vector <int>> dp(nums.size(), vector <int> (1001, 1));

    int ans = 2;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            dp[i][nums[i] - nums[j] + 500] = max(dp[i][nums[i] - nums[j] + 500], 1 + dp[j][nums[i] - nums[j] + 500]);
            ans = max(ans, dp[i][nums[i] - nums[j] + 500]);
        }
    }

    return ans;
}

int main() {
    return 0;
}