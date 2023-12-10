#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;



int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
    vector <vector <pair <int, int>>> graph(n);

    vector <vector <int>> edgeStore(n, vector <int> (n, 0));
    vector <vector <int>> edgeCons(n, vector <int> (n, 0));

    for (auto it: edges) {
        graph[it[0]].push_back({it[1], it[2]});
        graph[it[1]].push_back({it[0], it[2]});
        edgeStore[it[0]][it[1]] = it[2];
        edgeStore[it[1]][it[0]] = it[2];
    }        

    priority_queue <pair <int, int>> store;
    store.push({maxMoves, 0});

    vector <int> keep(n, -1);
    keep[0] = maxMoves;

    while (!store.empty()) {
        pair <int, int> hold = store.top();
        store.pop();

        for (auto it: graph[hold.second]) {
            if (hold.first - it.second > keep[it.first]) {
                keep[it.first] = hold.first - it.second;
                store.push({keep[it.first], it.first});
            }
        }
    }

    int ans = 0;
    for (auto it: keep) {
        if (it != -1) {
            ans++;
        }
    }


    for (auto it: edges) {
        ans += min(it[2], keep[it[0]] + keep[it[1]]);
    }

    return ans;
}

int main() {
    return 0;
}