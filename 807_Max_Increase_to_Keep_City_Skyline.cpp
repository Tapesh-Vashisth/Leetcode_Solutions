#include <iostream>
#include <vector>
using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    vector <int> rows;
    vector <int> cols;

    for (int i = 0; i < grid.size(); i++) {
        int maxr = INT32_MIN;
        int maxc = INT32_MIN;
        for (int j = 0; j < grid.size(); j++) {
            maxr = max(maxr, grid[i][j]);
            maxc = max(maxc, grid[j][i]);
        }

        rows[i] = maxr;
        cols[i] = maxc;
    }   

    int ans = 0;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid.size(); j++) {
            int row = rows[i];
            int col = cols[j];

            int hold = min(row, col);

            if (grid[i][j] < hold) {
                ans += (hold - grid[i][j]);
            }
        }
    }

    return ans;
}

int main() {
    return 0;
}