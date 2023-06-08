#include <iostream>
#include <vector>
using namespace std;

// Idea: we maintain a dp array that contains the maximum loot till each index. At every index i, we make a choice 
// whether loot till (i - 1)th house is greater or the loot of (i - 2)th house + current hosue i (since we can't take consecutive
// houses, we go for (i - 2)th index).

int rob(vector<int>& nums){

    // initiate the dp array with 2 zeroes 
    vector <int> dp = {0, 0};

    for (int i = 0; i < nums.size(); i++){
        // here, we make the choice at each index 
        dp.push_back(max(dp[dp.size() - 2] + nums[i], dp[dp.size() - 1]));
    }

    // return the maximum loot till the last house 
    return dp[dp.size() - 1];
}

int main(){
    return 0;
}