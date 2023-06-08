#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestBridge(vector<vector<int>>& grid) {
    queue <pair <int, int>> store;
    queue <pair <int, int>> store2;
    vector <vector <bool>> visited(grid.size(), vector <bool> (grid[0].size(), true));


    // get one island 
    for (int i = 0; i < grid.size(); i++) {
        bool decider = false;
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j]) {
                store.push({i, j});
                decider = true;
                break;
            }
        }

        if (decider) {
            break;
        }
    }

    int counter = 0;

    while (!store.empty()) {
        pair <int, int> hold = store.front();
        store.pop();

        if (visited[hold.first][hold.second] && grid[hold.first][hold.second]) {
            visited[hold.first][hold.second] = false;

            vector <int> xs = {0, 0, 1, -1};
            vector <int> ys = {1, -1, 0, 0};

            int decider = 0; 
            for (int i = 0; i < 4; i++) {
                int holdx = hold.first + xs[i];
                int holdy = hold.second + ys[i];

                if (holdx >= 0 && holdx < grid.size() && holdy >= 0 && holdy < grid[0].size() && grid[holdx][holdy] == 1) {
                    store.push({holdx, holdy});
                    decider++;
                }

            }

            if (decider != 4) {
                store2.push({hold.first, hold.second});
                counter++;
            }
        }
    }

    int turns = 0;

    while (!store2.empty()) {
        int temp = 0;
        while (counter--) {
            pair <int, int> hold = store2.front();
            store2.pop();

            vector <int> xs = {0, 0, 1, -1};
            vector <int> ys = {1, -1, 0, 0};

            for (int i = 0; i < 4; i++) {
                int holdx = hold.first + xs[i];
                int holdy = hold.second + ys[i];

                if (holdx >= 0 && holdx < grid.size() && holdy >= 0 && holdy < grid[0].size()) {
                    if (visited[holdx][holdy] && grid[holdx][holdy] == 0) {
                        visited[holdx][holdy] = false;
                        store2.push({holdx, holdy});
                        temp++;
                    } else if (visited[holdx][holdy] && grid[holdx][holdy] == 1) {
                        temp = 0;
                        counter = 0;
                        while (!store2.empty()) {
                            store2.pop();
                        }
                        break;
                    }   

                }
            }
        }
        counter = temp;
        turns++;
    }

    return turns - 1;
}

int main() {
    return 0;
}