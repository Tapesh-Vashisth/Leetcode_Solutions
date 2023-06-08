#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices){
    vector <int> dp = {0};
    int prev = prices[0];
    for (int i = 1; i < prices.size(); i++){
        if (prices[i] > prev){
            dp.push_back(dp[dp.size() - 1] + (prices[i] - prev));
        }else{
            dp.push_back(dp[dp.size() - 1]);
        }

        prev = prices[i];
    }

    return dp[prices.size() - 1];
}



int maxProfit(vector<int>& prices) {
    vector <vector <int>> dp(2, vector <int> (prices.size(), 0));

    dp[1][0] = -prices[0];

    for (int i = 1; i < prices.size(); i++) {
        // down
        dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - prices[i]);

        // up 
        dp[0][i] = max(dp[1][i] + prices[i], max(dp[0][i - 1], dp[1][i - 1] + prices[i]));
    }

    return dp[0][prices.size() - 1];       
}

int main(){
    vector <int> v = {1,2,3,4,5};
    cout << maxProfit(v) << endl;
    return 0;
}