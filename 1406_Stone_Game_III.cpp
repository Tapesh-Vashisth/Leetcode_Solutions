#include <iostream>
#include <vector>
using namespace std;

// turn == 0 --> alice 
// turn == 1 --> bob

vector <vector <int>> dp;

int helper(vector <int> & stoneValues, int index, int turn) {
    if (index >= stoneValues.size()) {
        return 0;
    }

    if (dp[turn][index] != -1) {
        return dp[turn][index];
    } 

    int ret = turn ? INT32_MAX : INT32_MIN;

    for (int i = 1; i <= 3; i++) {
        int total = 0;
        for (int j = index; j < stoneValues.size() && j < index + i; j++) {
            total += stoneValues[j];
        }

        int hold = (turn ? 0 : total) + helper(stoneValues, index + i, !turn);

        if (turn) {
            ret = min(ret, hold);
        } else {
            ret = max(ret, hold);
        }
    }

    dp[turn][index] = ret;

    return ret;
}

string stoneGameIII(vector<int>& stoneValue) {
    dp = vector <vector <int>> (2, vector <int> (stoneValue.size(), -1));
    int hold = helper(stoneValue, 0, 0);

    int total = 0;
    for (auto it: stoneValue) {
        total += it;
    }

    if (hold > total - hold) {
        return "Alice";
    } else if (hold < total - hold) {
        return "Bob";
    } else {
        return "Tie";
    }    
}

int main() {
    return 0;
}