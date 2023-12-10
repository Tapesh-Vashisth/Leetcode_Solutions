#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> xs = {0, 0, 1, -1};
vector <int> ys = {1, -1, 0, 0};

vector <vector <int>> dp;

int helper(int x, int y, vector <vector <int>> & matrix) {
    int ret = 0;

    if (dp[x][y] != -1) {
        return dp[x][y];
    }

    for (int i = 0; i < 4; i++) {
        int holdx = x + xs[i];
        int holdy = y + ys[i];

        if (holdx >= 0 && holdx < matrix.size() && holdy >= 0 && holdy < matrix[0].size()) {
            if (matrix[holdx][holdy] < matrix[x][y]) {
                ret = max(ret, helper(holdx, holdy, matrix));
            }
        }
    }

    dp[x][y] = ret + 1;

    return ret + 1;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    queue <pair <int, int>> store;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            bool decider = true;
            for (int k = 0; k < 4; k++) {
                int holdx = i + xs[k];
                int holdy = j + ys[k];

                if (holdx >= 0 && holdx < matrix.size() && holdy >= 0 && holdy < matrix[i].size()) {
                    if (matrix[holdx][holdy] > matrix[i][j]) {
                        decider = false;
                    }
                }
            }

            if (decider) {
                store.push({i, j});
            }
        }
    }    

    int ans = 0;

    dp.resize(matrix.size(), vector <int> (matrix[0].size(), -1));

    while (!store.empty()) {
        pair <int, int> hold = store.front();
        store.pop();

        ans = max(ans, helper(hold.first, hold.second, matrix));
    }

    return ans;
}

int main() {
    return 0;
}