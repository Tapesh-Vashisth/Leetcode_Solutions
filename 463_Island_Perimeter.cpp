#include <iostream>
#include <vector>
using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
    vector <int> xs = {0, 0, 1, -1};
    vector <int> ys = {1, -1, 0, 0};
    int ans = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    int holdx = i + xs[k];
                    int holdy = j + ys[k];

                    if (holdx >= 0 && holdx < grid.size() && holdy >= 0 && holdy < grid[i].size()) {
                        if (grid[holdx][holdy] == 0) {
                            ans++;
                        }
                    } else {
                        ans++;
                    }
                }
            }
        }
    }

    return ans;
}

int main() {
    return 0;
}