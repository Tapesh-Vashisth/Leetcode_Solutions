#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <vector <int>> down;
vector <int> up;

int helper(int current, int prev, vector <vector <int>> & tree) {
    int mx = 1;
    for (auto it: tree[current]) {
        if (it != prev) {
            int hold = helper(it, current, tree);
            down[current].push_back(hold + 1);
            mx = max(mx, hold + 1);
        }
    }

    return mx;
}

void mainHelper(int current, int prev, int upHeight, vector <vector <int>> & tree) {
    up[current] = upHeight;

    priority_queue <pair <int, int>> store;

    store.push({up[current], -1});
    bool check = false;
    for (int i = 0; i < tree[current].size(); i++) {
        if (tree[current][i] != prev) {
            if (check) {
                store.push({down[current][i - 1], i});
            } else {
                store.push({down[current][i], i});
            }
        } else {
            check = true;
        }
    }

    for (int i = 0; i < tree[current].size(); i++) {
        if (tree[current][i] != prev) {
            if (store.top().second != i) {
                mainHelper(tree[current][i], current, store.top().first + 1, tree);
            } else {
                pair <int, int> hold = store.top();
                store.pop();
                mainHelper(tree[current][i], current, store.top().first + 1, tree);
                store.push(hold);
            }
        }
    }
}       

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector <vector <int>> graph(n);

    for (auto it: edges) {
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }

    down = vector <vector <int>> (n);
    up = vector <int> (n, 0);

    int root = 0;

    helper(0, -1, graph);

    mainHelper(0, -1, 1, graph);

    vector <int> ans;

    int mn = INT32_MAX;
    for (int i = 0; i < n; i++) {
        int hold = 0;
        // up 
        hold = max(hold, up[i]);

        // down 
        for (auto it: down[i]) {
            hold = max(it, hold);
        }

        mn = min(mn, hold);
    }


    for (int i = 0; i < n; i++) {
        int hold = 0;
        // up 
        hold = max(hold, up[i]);

        // down 
        for (auto it: down[i]) {
            hold = max(it, hold);
        }

        if (hold == mn) {
            ans.push_back(i);
        }
    }
    
    return ans;
}

int main() {
    return 0;
}