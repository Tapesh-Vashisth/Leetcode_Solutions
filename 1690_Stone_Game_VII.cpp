#include <iostream>
#include <vector>
using namespace std;

// turn = 0 --> alice 
// turn = 1 --> bob 

vector <vector <int>> dp;

int helper(vector <int> & stones, int l, int r, vector <int> & prefixSum) {
    if (r <= l) {
        return 0;
    }

    if (dp[l][r] != -1) {
        return dp[l][r];
    }

    int turn = ((stones.size() - 1 - r) + l) % 2;
    
    // left
    int leftSum = (prefixSum[r] - prefixSum[l + 1]) + stones[l + 1]; 
    int left = helper(stones, l + 1, r, prefixSum) + (turn ? - leftSum : leftSum);

    // right 
    int rightSum = (prefixSum[r - 1] - prefixSum[l]) + stones[l];
    int right = helper(stones, l, r - 1, prefixSum) + (turn ? -rightSum : rightSum);

    int ret;

    if (turn) {
        ret = min(left, right);
    } else {
        ret = max(left, right);
    }

    dp[l][r] = ret;

    return ret;
}

int stoneGameVII(vector<int>& stones) {
    dp = vector <vector <int>> (stones.size(), vector <int> (stones.size(), -1));
    vector <int> prefixSum;

    int hold = 0;
    for (int i = 0; i < stones.size(); i++) {
        hold += stones[i];
        prefixSum.push_back(hold);
    }

    return helper(stones, 0, stones.size() - 1, prefixSum);    
}

int main() {

    return 0;
}