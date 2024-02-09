#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector <int> dp(nums.size(), 1);
    vector <int> parents(nums.size(), -1);

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    parents[i] = j;
                }
            }            
        }
    }


    vector <int> ans;

    int mxIndex = 0;
    int mxVal = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (dp[i] > mxVal) {
            mxIndex = i;
            mxVal = dp[i];
        }
    }

    int current = mxIndex;
    while (parents[current] != -1) {
        ans.push_back(nums[current]);

        current = parents[current];
    }

    ans.push_back(nums[current]);

    return ans; 
}

int main() {
    return 0;
}