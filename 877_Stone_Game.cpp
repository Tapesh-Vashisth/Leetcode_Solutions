#include <iostream>
#include <vector>
using namespace std;

// turn = 1 --> alice
// turn = 0 --> bob 
// helper function stands for the maximum score alice can get optimally 

vector <vector <vector <int>>> dp;

int helper(int turn, vector <int> & piles, int l, int r) {
    if (r < l) {
        return 0;
    }

    if (dp[turn][l][r] != -1) {
        return dp[turn][l][r];
    }

    int ret = turn ? INT32_MIN: INT32_MAX;

    // left 
    int left = (turn ? piles[l] : 0) + helper(!turn, piles, l + 1, r);

    // right 
    int right = (turn ? piles[r] : 0) + helper(!turn, piles, l, r - 1);

    if (turn) {
        ret = max(ret, max(left, right));
    } else {
        ret = min(ret, min(left, right));
    }

    dp[turn][l][r] = ret;

    return ret;
}

bool stoneGame(vector<int>& piles) {
    dp = vector <vector <vector <int>>> (2, vector <vector <int>> (piles.size(), vector <int> (piles.size(), -1)));
    int alice = helper(1, piles, 0, piles.size() - 1);

    int total = 0;
    for (auto it: piles) {
        total += it;
    }

    if (alice > total - alice) {
        return true;
    }

    return false;
}

int main() {
    return 0;
}