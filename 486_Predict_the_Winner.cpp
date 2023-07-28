#include <iostream>
#include <vector>
using namespace std;

vector <vector <int>> dp;

int helper(vector <int> & nums, int left, int right) {
    if (left > right) {
        return 0;
    }

    if (dp[left][right] != -1) {
        return dp[left][right];
    }

    // left 
    int leftHold = helper(nums, left + 1, right);

    // right 
    int rightHold = helper(nums, left, right - 1);

    int decider = left + (nums.size() - right);

    int ret;
    if (decider % 2) {
        ret = max(nums[left] + leftHold, nums[right] + rightHold);
    } else {
        ret = min(leftHold, rightHold);
    }

    dp[left][right] = ret;

    return ret;
}

bool PredictTheWinner(vector<int>& nums) {
    dp = vector <vector <int>> (nums.size(), vector <int> (nums.size(), -1));
    int total = 0;
    for (auto it: nums) {
        total += it;
    }

    int hold = helper(nums, 0, nums.size() - 1);

    if (hold >= total - hold) {
        return true;
    } else {
        return false;
    }
}

int main() {
    return 0;
}