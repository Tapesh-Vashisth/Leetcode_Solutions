#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int>& cost){
    vector <int> dp = {0, 0};
    for (int i = 2; i < cost.size(); i++){
        if (dp[dp.size() - 1] + cost[i - 1] > dp[dp.size() - 2] + cost[i - 2]){
            dp.push_back(dp[dp.size() - 2] + cost[i - 2]);
        }else{
            dp.push_back(dp[dp.size() - 1] + cost[i - 1]);
        }
    }

    return dp[dp.size() - 1];
}

int main(){
    return 0;
}