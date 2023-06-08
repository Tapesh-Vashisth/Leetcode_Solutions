#include <iostream>
#include <vector>
using namespace std;

    void dfs(int root, vector <vector <int>> & graph, vector <bool>& visited, vector <bool>& mainVisited, int & elements) {
        if (visited[root] == false) {
            visited[root] = true;
            mainVisited[root] = true;
            elements++;
            for (int i = 0; i < graph[root].size(); i++) {
                dfs(graph[root][i], graph, visited, mainVisited, elements);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector <long long> store;
        vector <vector <int>> graph(n);
        for (auto it: edges) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        int total = 0;
        vector <bool> mainVisited(n, false);
        for (int i = 0; i < mainVisited.size(); i++) {
            vector <bool> visited(n, false);
            int counter = 0;
            dfs(i, graph, visited, mainVisited, counter);
            store.push_back(counter);
            total += counter;
        }

        int ans = 0;

        for (auto it: store) {
            total -= it;
            ans += (it * total);
        }

        return ans;
    }

int main() {
    return 0;
}