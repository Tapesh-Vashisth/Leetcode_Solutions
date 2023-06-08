#include <vector>
#include <iostream>
using namespace std;

int maxSubarraySumCircularBruteForce(vector<int>& nums) {
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        nums.insert(nums.end(), nums[i]);
    }

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    vector <vector <int>> dp(len + 1, vector <int> (nums.size() + 1, 0));

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            dp[i][j] += dp[i][j - 1] + nums[j];
        }
    }

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            cout << dp[i][j] << " ";
        }  
        cout << endl;
    }

    return 0;
}

int maxSubarraySumCircular(vector<int>& nums) {
    int totalSum = 0;
    int tempMinSum = 0;
    int tempMaxSum = 0;
    int maxStraightSum = INT32_MIN;
    int minStraightSum = INT32_MAX;

    for (int i = 0; i < nums.size(); i++) {
        totalSum += nums[i];
        tempMinSum += nums[i];
        tempMaxSum += nums[i];
        maxStraightSum = max(maxStraightSum, tempMaxSum);
        minStraightSum = min(tempMinSum, minStraightSum);
        if (tempMaxSum < 0) {
            tempMaxSum = 0;
        }

        if (tempMinSum > 0) {
            tempMinSum = 0;
        }
    }

    return max(maxStraightSum, totalSum - minStraightSum);
}

int main() {
    return 0;
}