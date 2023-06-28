#include <iostream>
#include <vector>
#include <queue>
using namespace std;

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    vector <vector <pair <int, double>>> graph(n);

    int counter = 0;
    for (auto it: edges) {
        graph[it[0]].push_back({it[1], succProb[counter]});
        graph[it[1]].push_back({it[0], succProb[counter]});
        counter++;
    }

    priority_queue <pair <double, int>> store;
    store.push({1, start});

    vector <double> ans(n, 0);
    ans[start] = 1;

    while (!store.empty()) {

        pair <double, int> hold = store.top();
        ans[hold.second] = max(ans[hold.second], hold.first);
        store.pop();

        for (int i = 0; i < graph[hold.second].size(); i++) {
            double holdprob = hold.first * graph[hold.second][i].second;
            if (holdprob > ans[graph[hold.second][i].first]) {
                store.push({holdprob, graph[hold.second][i].first});
            }
        }
    }

    return ans[end];
}  

int main() {

    return 0;
}