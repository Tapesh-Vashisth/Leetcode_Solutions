#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;


int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    vector <vector <int>> keep(1e6 + 5);
    for (int i = 0; i < routes.size(); i++) {
        for (auto it: routes[i]) {
            keep[it].push_back(i);
        }
    }

    queue <pair <int, int>> store;
    vector <bool> visited(routes.size(), true);
    store.push({source, 0});

    while (!store.empty()) {
        pair <int, int> hold = store.front();
        store.pop();

        if (hold.first == target) {
            return hold.second;
        }

        for (auto & it: keep[hold.first]) {
            if (visited[it]) {
                visited[it] = false;
                for (int i = 0; i < routes[it].size(); i++) {
                    if (routes[it][i] == target) {
                        return hold.second + 1;
                    }

                    store.push({routes[it][i], hold.second + 1});
                }
            }
        }
    }

    return -1;
}

int main() {
    return 0;
}