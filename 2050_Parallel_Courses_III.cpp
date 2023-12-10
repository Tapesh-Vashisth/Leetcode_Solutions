#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector <vector <int>> graph(n);
    vector <int> inorder(n, 0);

    vector <int> store(n, 0);
    for (auto it: relations) {
        graph[it[1] - 1].push_back(it[0] - 1);
        inorder[it[0] - 1]++;
    }       

    priority_queue <pair <int, int>> keep;

    for (int i = 0; i < n; i++) {
        if (inorder[i] == 0) {
            keep.push({time[i], i});
            store[i] = time[i];
        }
    }


    while (!keep.empty()) {
        pair <int, int> hold = keep.top();
        keep.pop();

        for (auto it: graph[hold.second]) {
            if (store[it] < hold.first + time[it]) {
                store[it] = hold.first + time[it];
                keep.push({store[it], it});
            }
        }
    }

    int ans = 0;

    for (auto it: store) {
        ans = max(it, ans);
    }

    return ans;
}

int main() {
    return 0;
}