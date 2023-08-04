#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

bool isPrintable(vector<vector<int>>& targetGrid) {
    vector <pair <pair <int, int>, pair <int, int>>> store (61, {{INT32_MAX, INT32_MAX}, {INT32_MIN, INT32_MIN}});    

    for (int i = 0; i < targetGrid.size(); i++) {
        for (int j = 0; j < targetGrid[i].size(); j++) {
            store[targetGrid[i][j]].first.first = min(store[targetGrid[i][j]].first.first, i);
            store[targetGrid[i][j]].first.second = min(store[targetGrid[i][j]].first.second, j);
            store[targetGrid[i][j]].second.first = max(store[targetGrid[i][j]].second.first, i);
            store[targetGrid[i][j]].second.second = max(store[targetGrid[i][j]].second.second, j);
        }
    }       


    vector <set <int>> graph(61);
    vector <int> indegrees(61, 0);

    for (int i = 0; i < store.size(); i++) {
        if (store[i].first.first != INT32_MAX) {
            for (int j = store[i].first.first; j <= store[i].second.first; j++) {
                for (int k = store[i].first.second; k <= store[i].second.second; k++) {
                    if (targetGrid[j][k] != i) {
                        if (graph[i].count(targetGrid[j][k]) == 0) {
                            indegrees[targetGrid[j][k]]++;
                            graph[i].insert(targetGrid[j][k]);
                        }
                    }
                }
            }
        }
    }

    queue <int> keep;
    for (int i = 0; i < indegrees.size(); i++) {
        if (indegrees[i] == 0) {
            keep.push(i);
        }
    }

    while (!keep.empty()) {
        int hold = keep.front();
        keep.pop();

        for (auto it: graph[hold]) {
            indegrees[it]--;

            if (indegrees[it] == 0) {
                keep.push(it);
            }
        }
    }

    for (int i = 0; i < indegrees.size(); i++) {
        if (indegrees[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    return 0;
}