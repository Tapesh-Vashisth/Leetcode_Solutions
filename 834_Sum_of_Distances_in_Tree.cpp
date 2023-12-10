#include <iostream>
#include <vector>
using namespace std;

int helper(int current, int parent, vector <vector <int>> & graph, vector <int> & paths) {
    int ret = 1;

    for (auto it: graph[current]) {
        if (it != parent) {
            ret += helper(it, current, graph, paths);
        }
    }

    paths[current] = ret;

    return paths[current];
}

int calDistance(int current, int parent, vector <vector <int>> & graph, int hold) {
    int ret = hold;

    for (auto it: graph[current]) {
        if (it != parent) {
            ret += calDistance(it, current, graph, hold + 1);
        }
    }

    return ret == 0 ? hold: ret;
}

void construct(int current, int parent, vector <vector <int>> & graph, vector <int> & ans, vector <int> & paths) {
    if (ans[current] == -1) {
        ans[current] = ans[parent] + ((graph.size() - paths[current]) - paths[current]);

        for (auto it: graph[current]) {
            if (it != parent) {
                construct(it, current, graph, ans, paths);
            }
        }
    } else {
        for (auto it: graph[current]) {
            if (it != parent) {
                construct(it, current, graph, ans, paths);
            }
        }
    }
}

vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    vector <vector <int>> graph(n);
    vector <int> paths(n, 0);

    for (auto it: edges) {
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }

    helper(0, -1, graph, paths);

    vector <int> ans(n, -1);

    ans[0] = calDistance(0, -1, graph, 0);


    construct(0, -1, graph, ans, paths);

    return ans;
}

int main() {
    return 0;
}