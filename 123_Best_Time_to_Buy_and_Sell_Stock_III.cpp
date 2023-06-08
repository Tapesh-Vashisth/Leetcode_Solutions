#include <iostream>
#include <vector>
using namespace std;

vector <vector <vector <int>>> dp;

int helper(vector <int> & prices, int index, int buy, int round) {
    if (index == prices.size() || round == 3) {
        return 0;
    }

    if (dp[index][round - 1][buy] != -1) {
        return dp[index][round - 1][buy];
    }

    int ret = 0;

    if (round == 1) {
        if (buy) {
            int take = helper(prices, index + 1, !buy, round) - prices[index];
            int skip = helper(prices, index + 1, buy, round);

            ret = max(take, skip);
        } else {
            int take = helper(prices, index + 1, !buy, round + 1) + prices[index];
            int skip = helper(prices, index + 1, buy, round);

            ret = max(take, skip);
        }  
    } else if (round == 2) {
        if (buy) {
            int take = helper(prices, index + 1, !buy, round) - prices[index];
            int skip = helper(prices, index + 1, buy, round);

            ret = max(take, skip);
        } else {
            int take = helper(prices, index + 1, !buy, round + 1) + prices[index];
            int skip = helper(prices, index + 1, buy, round);

            ret = max(take, skip);
        }  
    }

    dp[index][round - 1][buy] = ret;

    return ret;
}

int maxProfit(vector<int>& prices) {
    dp = vector <vector <vector <int>>> (prices.size(), vector <vector <int>> (3, vector <int> (2, -1)));
    int ans = helper(prices, 0, 1, 1);

    return ans;
}

int main() {
    return 0;
}