#include <iostream>
#include <vector>
using namespace std;

void dfsHelper(int root, vector <vector <int>> & graph, vector <bool> & visited, vector <bool> & decider) {
    if (visited[root]) {
        decider[root] = false;
        visited[root] = false;
        for (int i = 0; i < graph[root].size(); i++) {
            dfsHelper(graph[root][i], graph, visited, decider);
        }
    }
}

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector <int> ans;
    
    vector <bool> decider(n, true);

    vector <vector <int>> graph(n);

    for (auto it: edges) {
        graph[it[0]].push_back(it[1]);
    }

    for (int i = 0; i < n; i++) {
        vector <bool> visited(n, true);
        if (decider[i]) {
            dfsHelper(i, graph, visited, decider);
            decider[i] = true;
        }
    }

    for (int i = 0; i < decider.size(); i++) {
        if (decider[i]) {
            ans.push_back(i);
        }
    }

    return ans;        
}

int main() {
    return 0;
}