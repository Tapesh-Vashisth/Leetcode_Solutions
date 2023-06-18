#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int countPaths(vector<vector<int>>& grid) {
    vector <vector <long long>> dp (grid.size(), vector <long long> (grid[0].size(), 1));

    priority_queue <pair <long long, pair <int, int>>> store;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            store.push({grid[i][j], {i, j}});
        }
    }

    vector <int> xs = {0, 0, 1, -1};
    vector <int> ys = {1, -1, 0, 0};

    long long ans = 0;
    while (!store.empty()) {
        pair <long long, pair <int, int>> hold = store.top();
        ans += dp[hold.second.first][hold.second.second];
        store.pop();

        for (int i = 0; i < xs.size(); i++) {
            int holdx = hold.second.first + xs[i];
            int holdy = hold.second.second + ys[i];

            if (holdx >= 0 && holdx < grid.size() && holdy >= 0 && holdy < grid[0].size()) {
                dp[holdx][holdy] += dp[hold.second.first][hold.second.second];
            }
        }
    }

    return ans;
}

int main() {
    return 0;
}