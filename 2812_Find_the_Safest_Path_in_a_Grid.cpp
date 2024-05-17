#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int maximumSafenessFactor(vector <vector <int>> & grid) {
    int n = grid.size();
    vector <vector <int>> updatedGrid(n, vector <int> (n, INT32_MAX));

    vector <int> xs = {1, -1, 0, 0};
    vector <int> ys = {0, 0, 1, -1};

    // [dist, x, y]
    priority_queue <vector <int>, vector<vector <int>>, greater<vector <int>>> store;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 1) {
                store.push({0, i, j});
                updatedGrid[i][j] = 0;
            }
        }
    }

    while (!store.empty()) {
        vector <int> hold = store.top();
        store.pop();

        for (int j = 0; j < 4; j++) {
            int holdx = hold[1] + xs[j];
            int holdy = hold[2] + ys[j];

            if (holdx >= 0 && holdx < n && holdy >= 0 && holdy < n && (hold[0] + 1) < updatedGrid[holdx][holdy]) {
                updatedGrid[holdx][holdy] = hold[0] + 1;
                store.push({updatedGrid[holdx][holdy], holdx, holdy});
            }
        }
    }


    priority_queue <vector <int>> keep;
    vector <vector <int>> dp(n, vector <int> (n, 0));
    dp[0][0] = updatedGrid[0][0];

    keep.push({dp[0][0], 0, 0});

    while (!keep.empty()) {
        vector <int> hold = keep.top();
        keep.pop();

        for (int i = 0; i < 4; i++) {
            int holdx = hold[1] + xs[i];
            int holdy = hold[2] + ys[i];

            if (holdx >= 0 && holdx < n && holdy >= 0 && holdy < n) {
                int value = min(hold[0], updatedGrid[holdx][holdy]);

                if (value > dp[holdx][holdy]) {
                    dp[holdx][holdy] = value;

                    keep.push({dp[holdx][holdy], holdx, holdy});
                }
            }
        }
    }

    return dp[n - 1][n - 1];
}

int main() {
    return 0;
}