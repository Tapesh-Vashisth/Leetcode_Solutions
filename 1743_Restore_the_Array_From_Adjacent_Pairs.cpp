#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    map <int, int> inorder;
    map <int, vector <int>> graph;

    for (auto it: adjacentPairs) {
        inorder[it[0]]++;
        inorder[it[1]]++;
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }        

    vector <int> ans(adjacentPairs.size() + 1, -1);

    queue <pair <int, int>> store;

    bool check = false;
    for (auto it: inorder) {
        if (it.second == 1) {
            if (check) {
                ans[adjacentPairs.size()] = it.first;
            } else {
                store.push({it.first, 0});
                check = true;
            }
        }
    }

    while (!store.empty()) {
        pair <int, int> hold = store.front();
        store.pop();

        ans[hold.second] = hold.first;

        for (auto it: graph[hold.first]) {
            inorder[it]--;

            if (inorder[it] == 1) {
                store.push({it, hold.second + 1});
            }
        }
    }

    return ans;
}

int main() {
    return 0;
}