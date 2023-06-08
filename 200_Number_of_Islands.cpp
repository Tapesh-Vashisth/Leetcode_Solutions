#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void bfs(vector <vector <char>> grid, int x, int y, vector <vector <bool>> & visited) {
    queue <pair <int, int>> store;

    store.push({x, y});
    vector <vector <bool>> thisVisited(grid.size(), vector <bool> (grid[0].size(), true));
    while (!store.empty()) {
        pair <int, int> hold = store.front();
        store.pop();
        if (thisVisited[hold.first][hold.second]) {
            visited[hold.first][hold.second] = false;
            thisVisited[hold.first][hold.second] = false;

            // up 
            if (hold.first - 1 >= 0 && grid[hold.first - 1][hold.second] == '1') {
                store.push({hold.first - 1, hold.second});
            }

            // down 
            if (hold.first + 1 < grid.size() && grid[hold.first + 1][hold.second] == '1') {
                store.push({hold.first + 1, hold.second});
            }
    
            // left 
            if (hold.second - 1 >= 0 && grid[hold.first][hold.second - 1] == '1') {
                store.push({hold.first, hold.second - 1});
            }

            // right
            if (hold.second + 1 < grid[0].size() && grid[hold.first][hold.second + 1] == '1') {
                store.push({hold.first, hold.second + 1});
            } 
        }
    }
}


int numIslands(vector<vector<char>>& grid) {
    vector <vector <bool>> visited(grid.size(), vector <bool> (grid[0].size(), true));
    
    int ans = 0; 

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '1') {
                if (visited[i][j]) {
                    ;
                } else {
                    bfs(grid, i, j, visited);
                    ans++;
                }
            } 
        }
    }


    return ans;
}

int findParent(vector <int> & parents, int x) {
    if (parents[x] != x) {
        int hold = findParent(parents, parents[x]);
        parents[x] = hold;
        return hold;
    }

    return x;
}

void U(vector <int> & parents, int x, int y) {
    int first = findParent(parents, x);
    int second = findParent(parents, y);

    if (first != second) {
        parents[first] = second; 
    }
}

int numIslands(vector<vector<char>>& grid) {
    vector <int> parents(grid.size() * grid[0].size());

    for (int i = 0; i < parents.size(); i++) {
        parents[i] = i;
    }   

    int counter = 0;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '1') {
                if (i + 1 < grid.size() && grid[i + 1][j] == '1') {
                    U(parents, counter, counter + grid[i].size());
                }

                if (j + 1 < grid[i].size() && grid[i][j + 1] == '1') {
                    U(parents, counter, counter + 1);
                }
            }

            counter++;
        }
    }

    int ans = 0;
    counter = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            ans += grid[i][j] == '1' && parents[counter] == counter;
            counter++;
        }
    }


    return ans;
}

int main() {
    return 0;
}