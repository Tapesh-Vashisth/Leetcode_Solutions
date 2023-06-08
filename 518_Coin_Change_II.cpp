#include <iostream>
#include <vector>
using namespace std;

vector <vector <int>> dp;

int helper(int amount, vector <int> & coins, int index, int total) {
    if (total > amount) {
        return 0;
    } else if (total == amount) {
        return 1;
    }

    if (dp[index][total] != -1) {
        return dp[index][total];
    }

    int counter = 0;
    for (int i = index; i < coins.size(); i++) {
        counter += helper(amount, coins, i, total + coins[i]);
    }

    dp[index][total] = counter;

    return counter;
}

int change(int amount, vector<int>& coins) {
    dp = vector <vector <int>> (coins.size(), vector <int> (amount + 1, -1));
    int ans = helper(amount, coins, 0, 0);
    return ans;
}

int main() {
    return 0;
}
