#include <iostream>
#include <vector>
using namespace std;

vector <vector <vector <int>>> dp;

bool helper(vector <int> & nums, int first, int second, int current) {
    if (current >= nums.size()) {
        if (first == second) {
            return true;
        } else {
            return false;
        }
    }

    if (dp[current][first][second] != -1) {
        return dp[current][first][second];
    }

    bool up = helper(nums, first + nums[current], second, current + 1);
    bool down;
    if (!up) {
        down = helper(nums, first, second + nums[current], current + 1);
    }

    bool ans = false;
    if (up || down) {
        ans = true;
    }   

    dp[current][first][second] = ans;

    return ans;
}


bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector <vector <bool>> dp(n + 1, vector <bool> (k + 1, false));

    for (int i = 0; i < n + 1; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < k + 1; j++) {
            if (j - arr[i - 1] >= 0 && dp[i - 1][j - arr[i - 1]]) {
                dp[i][j] = true;
            } else if (dp[i - 1][j]) {
                dp[i][j] = true;
            }
        }



        if (dp[i][k]) {
            return true;
        }
    }

    return false;
}


bool canPartition(vector<int>& nums) {
    int total = 0;
    for (auto it: nums) {
        total += it;
    }

    if (total % 2 == 1) {
        return false;
    } else {
        return subsetSumToK(nums.size(), total/2, nums);
    }
}

int main() {
    return 0;
}