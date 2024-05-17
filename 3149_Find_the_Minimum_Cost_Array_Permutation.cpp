#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector <vector <pair <int, int>>> dp;

void helper(int prev, int taken, int mask, vector <int> & nums) {
    if (dp[prev][mask].first != -1) {
        return;
    }

    if (taken == nums.size()) {
        pair <int, int> ret;
        ret.first = abs(prev - nums[0]);
        ret.second = -1;

        dp[prev][mask] = ret;
        return;
    }

    pair <int, int> ret;
    ret.first = INT32_MAX;
    for (int i = 0; i < nums.size(); i++) { 
        if (!(mask & (1 << i))) {
            helper(i, taken + 1, mask | (1 << i), nums);
            pair <int, int> hold = dp[i][mask | (1 << i)];
            hold.first += abs(prev - nums[i]);
            hold.second = i;

            if (hold.first < ret.first) {
                ret = hold;
            }
        }
    }   

    dp[prev][mask] = ret;
}

vector<int> findPermutation(vector<int>& nums) {
    dp = vector <vector <pair <int, int>>> (nums.size(), vector <pair <int, int>> ((1 << (nums.size())) + 1, std::make_pair (-1, -1)));
    helper(0, 1, (1 << 0), nums);
    
    vector <int> ans;
    int current = 0;
    int mask = (1 << 0);
    while (current != -1) {
        ans.push_back(current);
        current = dp[current][mask].second;
        mask = (mask | (1 << dp[current][mask].second));
    }

    return ans;
}

// vector <int> iterative(vector <int> & nums) {
//     dp = vector <vector <pair <int, vector <int>>>> (nums.size(), vector <pair <int, vector <int>>> ((1 << (nums.size())) + 1, std::make_pair (-1, vector <int> ())));
// }

int main() {
    return 0;
}