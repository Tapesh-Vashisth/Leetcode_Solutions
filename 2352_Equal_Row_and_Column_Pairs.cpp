#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int equalPairs(vector<vector<int>>& grid) {
    vector <string> rows;
    vector <string> cols;
    
    unordered_map <string, int> store;

    for (int i = 0; i < grid.size(); i++) {
        string row = "";
        string col = "";
        for (int j = 0; j < grid[i].size(); j++) {
            row.append(to_string(grid[i][j]) + "-");
            col.append(to_string(grid[j][i]) + "-");
        }

        store[row]++;
        rows.push_back(row);
        cols.push_back(col);
    }

    int ans = 0;
    for (auto it: cols) {
        ans += store[it];
    }

    return ans;
}

int main() {
    return 0;
}