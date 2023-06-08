#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
void dfs(int root, vector <vector <int>> & graph, vector <bool> & visited, vector <bool> & mainVisited, int size) {
    if (visited[root] == false) {
        visited[root] = true;
        for (int i = 0; i < graph[root].size(); i++) {
            dfs(root, graph, visited, mainVisited, size + 1);
        }
    } else {
        ans = max(ans, size);
    }
}


int longestCycle(vector<int>& edges) {
    vector <vector <int>> graph(edges.size());

    for (int i = 0; i < edges.size(); i++) {
        graph[i].push_back(edges[i]);
    }

    ans = 0;
    vector <bool> mainVisited(edges.size(), false);
    for (int i = 0; i < edges.size(); i++) {
        if (mainVisited[i] == false) {
            vector <bool> visited(edges.size(), false);
            dfs(i, graph, visited, mainVisited, 0);
        }
    }

    return ans;
}

int main() {
    return 0;
}