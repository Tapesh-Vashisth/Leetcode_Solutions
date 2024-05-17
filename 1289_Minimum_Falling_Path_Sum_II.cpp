#include <iostream>
#include <vector>
using namespace std;

int minFallingPathSum(vector<vector<int>>& grid) {
    vector <vector <int>> dp(grid.size() + 1, vector <int> (grid[0].size(), 0));        

    for (int i = 1; i <= grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            int mn = INT32_MAX;
            for (int k = 0; k < grid[i].size(); i++) {
                if (k != j) {
                    mn = min(mn, dp[i - 1][j]);
                }
            }

            dp[i][j] = mn + grid[i][j];
        }
    }


    int ans = INT32_MAX;

    for (int i = 0; i < grid[0].size(); i++) {
        ans = min(ans, dp[grid.size()][i]);
    }

    return ans;
}

int main() {
    return 0;
}