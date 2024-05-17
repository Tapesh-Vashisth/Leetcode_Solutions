#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    int n = grid.size();
    vector <vector <int>> ans(n - 2, vector <int> (n - 2, 0));
    
    vector <int> xs = {0, 0, 0, 1, 1, 1, -1, -1, -1};
    vector <int> ys = {0, 1, -1, 0, 1, -1, 0, 1, -1};

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            int centerx = i + 1;
            int centery = j + 1;

            for (int k = 0; k < xs.size(); k++) {
                ans[i][j] = max(ans[i][j], grid[centerx + xs[k]][centery + ys[k]]);
            }
        }
    }

    return ans;
}

int main() {
    return 0;
}