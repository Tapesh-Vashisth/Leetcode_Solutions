#include <iostream>
#include <vector>
using namespace std;

// turn == 0 --> alice 
// turn == 1 --> bob 

vector <vector <vector <int>>> dp;

int helper(int turn, vector <int> & piles, int i, int m) {
    if (i == piles.size()) { 
        return 0;
    }

    if (dp[turn][i][m] != -1) {
        return dp[turn][i][m];
    }

    int ret = turn ? INT32_MAX: INT32_MIN;

    for (int j = 1; j <= min(2*m, (int)piles.size() - i); j++) {
        int hold = 0;
        for (int a = i; a < i + j; a++) {
            hold += piles[a];
        }


        int temp = (turn == 0 ? hold : 0) + helper(!turn, piles, i + j, max(m, j));

        if (turn) {
            ret = min(ret, temp);
        } else {
            ret = max(ret, temp);
        }
    }

    dp[turn][i][m] = ret;

    return ret;
}

int stoneGameII(vector<int>& piles) {
    dp = vector <vector <vector <int>>> (2, vector <vector <int>> (piles.size() + 1, vector <int> (piles.size() + 1, -1)));
    return helper(0, piles, 0, 1);
}

int main() {
    return 0;
}