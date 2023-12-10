#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int catMouseGame(vector<vector<int>>& graph) {
    int n = graph.size();

    vector <vector <vector <int>>> dp (n, vector <vector <int>> (n, vector <int> (2, 0)));
    queue <vector <int>> store;
    for (int i = 0; i < n; i++) {
        dp[0][i][1] = 1;
        dp[0][i][2] = 1;
        store.push({0, i, 1});
        store.push({0, i, 2});
    }        

    for (int i = 0; i < n; i++) {
        dp[i][i][1] = 2;
        dp[i][i][2] = 2;
        store.push({i, i, 1});
        store.push({i, i, 2});
    }

    while (!store.empty()) {
        vector <int> hold = store.front();
        store.pop();

        if (hold[2] == 1) {
            for (auto it: graph[hold[0]]) {
                if (dp[it][hold[1]][2] > 0) {
                    continue;
                } else {
                    if (dp[hold[0]][hold[1]][hold[2]] == 2) {
                        dp[it][hold[1]][2] = 2;
                    }
                }
            }
        } else {
            for (auto it: graph[hold[1]]) {
                if (dp[hold[0]][it][1] > 0) {
                    continue;
                } else {
                    if (dp[hold[0]][hold[1]][hold[2]] == 1) {
                        dp[it][hold[1]][1] = 1;
                    }
                }
            }
        }
    }

    return dp[1][2][1];
}

int main() {
    return 0;
}