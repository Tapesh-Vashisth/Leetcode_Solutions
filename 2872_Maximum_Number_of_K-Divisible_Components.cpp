#include <iostream>
#include <vector>
using namespace std;

int ans = 0;

int helper(int current, vector <vector <int>> & graph, vector <int> & values, int k, int prev) {
    int ret = values[current];

    for (auto it: graph[current]) {
        if (it != current) {
            int hold = helper(current, graph, values, k, current);

            if (hold % k == 0) {
                ans++;
            } else {
                ret += hold;
            }
        }
    }

    return ret;
}

int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    vector <vector <int>> graph(n);

    for (auto it: edges) {
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }

    helper(0, graph, values, k, -1);

    return ans;
}

int main() {
    return 0;
}