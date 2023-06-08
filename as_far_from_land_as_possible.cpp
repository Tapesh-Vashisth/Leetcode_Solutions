#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// int maxDistance(vector<vector<int>>& grid) {
//     int n = grid.size();
//     vector <vector <int>> store(n, vector <int> (n, 0));
//     queue <pair <int, int>> q; 
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             store.clear();
//             if (grid[i][j]) {
//                 vector <vector<bool>> visited(n, vector <bool> (n, false));
//                 q.push({i, j});
//                 int dist = 1;
//                 while (!q.empty()) {
//                     pair <int, int> hold = q.front();
//                     q.pop();
//                     int x = hold.first;
//                     int y = hold.second;
//                     visited[x][y] = true;
//                     // left 
//                     if (y - 1 >= 0) {
//                         if (grid[x][y - 1] != 1 && visited[x][y - 1] == false) {
//                             if (store[x][y - 1] < dist) {
//                                 store[x][y - 1] = dist;
//                                 q.push({x, y - 1});
//                             }
//                         }
//                     }

//                     // right 
//                     if (y + 1 < n) {
//                         if (grid[x][y + 1] != 1 && visited[x][y + 1] == false) {
//                             if (store[x][y + 1] < dist) {
//                                 store[x][y + 1] = dist;
//                                 q.push({x, y + 1});
//                             }
//                         }
//                     }

//                     // up 
//                     if (x - 1 >= 0) {
//                         if (grid[x - 1][y] != 1 && visited[x - 1][y] == false) {
//                             if (store[x - 1][y] < dist) {
//                                 store[x - 1][y] = dist;
//                                 q.push({x - 1, y});
//                             }
//                         }
//                     }

//                     // down 
//                     if (x + 1 < n) {
//                         if (grid[x + 1][y] != 1 && visited[x + 1][y] == false) {
//                             if (store[x + 1][y] < dist) {
//                                 store[x + 1][y] = dist;
//                                 q.push({x + 1, y});
//                             }
//                         }
//                     }

//                     dist++;
//                 }
//             }
//         }
//     }

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cout << store[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

int maxDistance(vector<vector<int>>& grid) {
    vector <pair <int, int>> ones;
    vector <pair <int, int>> zeroes;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 1) {
                ones.push_back({i, j});
            } else {
                zeroes.push_back({i, j});
            }
        }
    }

    if (zeroes.size() == 0 || ones.size() == 0) {
        return -1;
    }

    int l = 0;
    int h = 200;
    int ans = -1;
    for (auto i: zeroes) {
        int dist = 1000;
        for (auto j: ones) {
            dist = min(dist, abs(i.first - j.first) + abs(i.second - j.second));
        }
        ans = max(dist, ans);
    }

    return ans;
}

int main() {
    return 0;
}