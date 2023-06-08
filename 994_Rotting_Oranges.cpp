#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int ans = 0;
    
    queue <pair <int, int>> store;
    vector <vector <bool>> visited(grid.size(), vector <bool> (grid[0].size(), true));

    int counter = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 2) {
                store.push({i, j});
                counter++;
            }
        }
    }    


    while (!store.empty()) {
        int temp = 0;
        while (counter--) {
            pair <int, int> hold = store.front();
            store.pop();

            if (visited[hold.first][hold.second]) {
                visited[hold.first][hold.second] = false;

                // up 
                if (hold.first - 1 >= 0 && visited[hold.first - 1][hold.second]) {
                    store.push({hold.first - 1, hold.second});
                    temp++;
                }

                // down 
                if (hold.first + 1 < grid.size()  && visited[hold.first + 1][hold.second]) {
                    store.push({hold.first + 1, hold.second});
                    temp++;
                }

                // left 
                if (hold.second - 1 >= 0 && visited[hold.first][hold.second - 1]) {
                    store.push({hold.first, hold.second - 1});
                    temp++;
                }

                // right 
                if (hold.second + 1 >= grid[0].size() && visited[hold.first][hold.second + 1]) {
                    store.push({hold.first, hold.second + 1});
                    temp++;
                }
            }
        }

        counter = temp;
        ans++;
    }

    return ans;
}

int main() {
    return 0;
}