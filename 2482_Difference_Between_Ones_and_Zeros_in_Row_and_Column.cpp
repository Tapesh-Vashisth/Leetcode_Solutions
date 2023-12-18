#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    vector <int> rowOnes(grid.size(), 0);
    vector <int> columnOnes(grid[0].size(), 0);

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 1) {
                rowOnes[i]++;
                columnOnes[j]++;
            }
        }
    }        

    vector <vector <int>> ans(grid.size(), vector <int> (grid[0].size(), 0));

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            ans[i][j] = 2 * (rowOnes[i] + columnOnes[j]) - grid.size() - grid[0].size();
        }
    }        

    return ans;
}

int main() {
    return 0;
}