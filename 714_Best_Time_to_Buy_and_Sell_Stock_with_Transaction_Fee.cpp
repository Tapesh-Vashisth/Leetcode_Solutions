#include <iostream>
#include <vector>
using namespace std;

vector <vector <int>> dp;

int helper(vector <int> & prices, int fee, int index, int buy) {
    if (index == prices.size()) {
        return 0;
    }

    if (dp[index][buy] != -1) {
        return dp[index][buy];
    }

    int profit = 0;
    if (buy) {
        int take = helper(prices, fee, index + 1, !buy) - prices[index];
        int skip = helper(prices, fee, index + 1, buy);

        profit = max(take, skip);
    } else {
        int take = helper(prices, fee, index + 1, !buy) + prices[index] - fee;
        int skip = helper(prices, fee, index + 1, buy);

        profit = max(take, skip);
    }

    dp[index][buy] = profit;

    return profit;
}

int maxProfit(vector<int>& prices, int fee) {
    dp = vector <vector <int>> (prices.size(), vector <int> (2, -1));
    return helper(prices, fee, 0, 1);
}

int main() {
    return 0;
}