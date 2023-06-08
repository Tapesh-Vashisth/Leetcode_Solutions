#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
    vector <vector <pair <int, int>>> graph(n);
    for (auto it: roads) {
        graph[it[0]].push_back({it[1], it[2]});
        graph[it[1]].push_back({it[0], it[2]});
    }

    vector <pair <int, int>> dists(n, {INT32_MAX, INT32_MAX});
    dists[0] = {0, 1};
    priority_queue <pair <int, pair <int, int>>, vector<pair <int, pair <int, int>>>, greater<pair <int, pair <int, int>>>> gp;
    gp.push({0, {0, 1}});

    while (!gp.empty()) {
        pair <int, pair <int, int>> hold = gp.top();
        gp.pop();

        for (int i = 0; i < graph[hold.first].size(); i++) {
            int cost = hold.second.first + graph[hold.first][i].second;

            if (cost < dists[graph[hold.first][i].first].first) {
                gp.push({graph[hold.first][i].first, {cost, hold.second.second}});                
            } else if (cost == dists[graph[hold.first][i].first].first) {
                gp.push({graph[hold.first][i].first, {cost, dists[graph[hold.first][i].first].second + hold.second.second}});
            }
        }
    }

    return dists[n - 1].second;
}

int main() {
    return 0;
}