#include <iostream>
#include <vector>
using namespace std;

vector <vector <pair <int, vector <pair <int, int>>>>> dp;

pair <int, vector<pair <int, int>>> helper(vector <vector <int>> & grid, int x, int y, int type) {
    if (type == 1) {
        if (x == grid.size() - 1 && y == grid.size() - 1) {
            return {grid[x][y], {{x, y}}};
        } else if (x >= grid.size() || y >= grid.size() || grid[x][y] == -1) {
            return {INT32_MIN, {}};
        }

        pair <int, vector<pair <int, int>>> right = helper(grid, x, y + 1, type);
        pair <int, vector<pair <int, int>>> down = helper(grid, x + 1, y, type);


        if (right.first > down.first) {
            right.first += grid[x][y];
            right.second.push_back({x, y});          

            return right;  
        } else {
            down.first += grid[x][y];
            down.second.push_back({x, y});            

            return down;
        }
    } else {    

    }
}   

int cherryPickup(vector<vector<int>>& grid) {
    dp = vector <vector <pair <int, vector <pair <int, int>>>>> (grid.size(), vector <pair <int, vector <pair <int, int>>>> (grid.size(), {-1, {}}));
    pair <int, vector <pair <int, int>>> down = helper(grid, 0, 0, 1);

    for (auto it: down.second) {
        cout << it.first << " " << it.second << endl;
    }
}

int main() {
    return 0;
}