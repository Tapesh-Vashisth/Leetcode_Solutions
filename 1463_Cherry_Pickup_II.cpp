#include <iostream>
#include <vector>
using namespace std;

int helper(int r, int c1, int c2, vector <vector <int>> & grid, vector <vector <vector <int>>> & dp) {
    if (r == grid.size() - 1) {
        return grid[r][c1] + (c1 != c2 ? grid[r][c2] : 0);
    }

    if (dp[r][c1][c2] != -1) {
        return dp[r][c1][c2];
    }

    int ret = grid[r][c1] + (c1 != c2 ? grid[r][c2] : 0);

    int mx = INT32_MIN;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int holdc1 = c1 + i;
            int holdc2 = c2 + j;

            if (holdc1 >= 0 && holdc1 < grid[r].size() && holdc2 >= 0 && holdc2 < grid[r].size()) {
                mx = max(mx, helper(r + 1, holdc1, holdc2, grid, dp));
            }
        }
    }

    dp[r][c1][c2] = ret + mx;

    return dp[r][c1][c2];
}

int cherryPickup(vector<vector<int>>& grid) {
    vector <vector <vector <int>>> dp (grid.size(), vector <vector <int>> (grid[0].size(), vector <int> (grid[0].size(), -1)));
    return helper(0, 0, grid[0].size() - 1, grid, dp);
}

int main() {
    return 0;
}