#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

bool intersectOrNot(long long x1, long long y1, long long r1, long long x2, long long y2, long long r2) {
    long long dist = ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    if (r1*r1 >= dist) {
        return true;
    }

    return false;
}

int maximumDetonation(vector<vector<int>>& bombs) {
    vector <vector <int>> graph(bombs.size());
    
    for (int i = 0; i < bombs.size(); i++) {
        for (int j = i + 1; j < bombs.size(); j++) {
            bool decider = intersectOrNot(bombs[i][0], bombs[i][1], bombs[i][2] + 1, bombs[j][0], bombs[j][1], bombs[j][2] + 1);
            if (decider) {
                graph[i].push_back(j);
            }
        }
    }

    int ans = INT32_MIN;

    for (int i = 0; i < bombs.size(); i++) {
        queue <int> store;
        store.push(i);
        vector <bool> visited(bombs.size(), true);

        int temp = 0;

        while (!store.empty()) {
            int hold = store.front();
            store.pop();

            if (visited[hold]) {
                visited[hold] = false;
                temp++;

                for (auto it: graph[hold]) {
                    store.push(it);
                }
            }
        }

        ans = max(ans, temp);
    }

    return ans;
}

int main() {
    return 0;
}