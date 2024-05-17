#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

vector <int> xs = {1, -1, 0, 0};
vector <int> ys = {0, 0, 1, -1};

int helper(int x, int y, vector <vector <int>> & grid, map <pair <int, int>, int> & hold) {
    // [score, mask, x, y]
    priority_queue <vector <int>> store;
    int ret = grid[x][y];

    vector <vector <int>> dp(grid.size(), vector <int> (grid[0].size(), 0));
    dp[x][y] = grid[x][y];
    store.push({dp[x][y], (1 << hold[{x, y}]), x, y});

    while (!store.empty()) {
        vector <int> keep = store.top();
        store.pop();

        for (int i = 0; i < xs.size(); i++) {
            int holdx = keep[2] + xs[i];
            int holdy = keep[3] + ys[i];

            if (holdx >= 0 && holdx < grid.size() && holdy >= 0 && holdy < grid[holdx].size() && grid[holdx][holdy] > 0 && (keep[1] & (1 << (hold[{holdx, holdy}]))) == 0) {
                dp[holdx][holdy] = max(dp[holdx][holdy], keep[0] + grid[holdx][holdy]);

                ret = max(ret, dp[holdx][holdy]);
                store.push({keep[0] + grid[holdx][holdy], (keep[1] | (1 << hold[{holdx, holdy}])), holdx, holdy});
            }
        }
    }

    return ret;
}

int getMaximumGold(vector<vector<int>>& grid) {
    int ans = 0;

    map <pair <int, int>, int> hold;
    int counter = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] > 0) {
                hold[{i, j}] = counter;
                counter++;
            }
        }
    }        

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] > 0) {
                ans = max(ans, helper(i, j, grid, hold));
            }
        }
    }

    return ans;
}

int main() {
    return 0;
}