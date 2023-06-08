#include <iostream>
#include <vector>
using namespace std;

int countNegatives(vector<vector<int>>& grid) {
    int x = grid.size() - 1;
    int y = 0;

    int ans = 0;
    while (y < grid[0].size() && x >= 0) {
        while (y < grid[x].size() && grid[x][y] >= 0) {
            y++;
        }

        ans += (grid[x].size() - y);

        x--;
    }

    return ans;
}

int main() {
    return 0;
}