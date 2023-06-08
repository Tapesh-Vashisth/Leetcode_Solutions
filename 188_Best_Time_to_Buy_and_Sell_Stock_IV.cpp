#include <iostream>
#include <vector>
using namespace std;

vector <vector <vector <int>>> dp;

int helper(vector <int> & prices, int index, int buy, int round, int k) {
    if (index == prices.size()) {
        return 0;
    }

    if (dp[index][round - 1][buy] != -1) {
        return dp[index][round - 1][buy];
    }

    int ret = 0;

    if (round < k) {
        if (buy) {
            int take = helper(prices, index + 1, !buy, round, k) - prices[index];
            int skip = helper(prices, index + 1, buy, round, k);

            ret = max(take, skip);
        } else {
            int take = helper(prices, index + 1, !buy, round + 1, k) + prices[index];
            int skip = helper(prices, index + 1, buy, round, k);

            ret = max(take, skip);
        }  
    } else if (round == k) {
        if (buy) {
            int take = helper(prices, index + 1, !buy, round, k) - prices[index];
            int skip = helper(prices, index + 1, buy, round, k);

            ret = max(take, skip);
        } else {
            int take = helper(prices, index + 1, !buy, round + 1, k) + prices[index];
            int skip = helper(prices, index + 1, buy, round, k);

            ret = max(take, skip);
        }  
    }

    dp[index][round - 1][buy] = ret;

    return ret;
}

int maxProfit(int k, vector<int>& prices) {
    dp = vector <vector <vector <int>>> (prices.size(), vector <vector <int>> (k + 1, vector <int> (2, -1)));
    int ans = helper(prices, 0, 1, 1, k);

    return ans;
}

int main() {
    return 0;
}