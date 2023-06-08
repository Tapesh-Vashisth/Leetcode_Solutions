#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    vector <vector <int>> dp(grid.size(), vector <int> (grid[0].size(), 0));        
    dp[0][0] = grid[0][0];
    for (int i = 1; i < dp[0].size(); i++){
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }

    for (int i = 1; i < dp.size(); i++){
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < dp.size(); i++){
        for (int j = 1; j < dp[0].size(); j++){
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[dp.size() - 1][dp[0].size() - 1];
}

int main(){
    return 0;
}