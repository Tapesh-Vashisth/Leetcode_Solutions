#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector <vector <int>> & grid, int x, int y, int colour) {
    queue <pair <int, int>> store;

    store.push({x, y});
    int startingColor = grid[x][y];
    vector <vector <bool>> thisVisited(grid.size(), vector <bool> (grid[0].size(), true));
    while (!store.empty()) {
        pair <int, int> hold = store.front();
        store.pop();
        if (thisVisited[hold.first][hold.second]) {
            thisVisited[hold.first][hold.second] = false;
            grid[hold.first][hold.second] = colour;
            // up 
            if (hold.first - 1 >= 0 && grid[hold.first - 1][hold.second] == startingColor) {
                store.push({hold.first - 1, hold.second});
            }

            // down 
            if (hold.first + 1 < grid.size() && grid[hold.first + 1][hold.second] == startingColor) {
                store.push({hold.first + 1, hold.second});
            }
    
            // left 
            if (hold.second - 1 >= 0 && grid[hold.first][hold.second - 1] == startingColor) {
                store.push({hold.first, hold.second - 1});
            }

            // right
            if (hold.second + 1 < grid[0].size() && grid[hold.first][hold.second + 1] == startingColor) {
                store.push({hold.first, hold.second + 1});
            } 
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    bfs(image, sr, sc, color);

    return image;    
}

int main() {
    return 0;
}