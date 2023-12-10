#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    vector <vector <pair <int, int>>> gr;    

    Graph(int n, vector<vector<int>>& edges) {
        gr.resize(n);

        for (auto it: edges) {
            gr[it[0]].push_back({it[1], it[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        gr[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector <int> dists(gr.size(), INT32_MAX);
        dists[node1] = 0;

        priority_queue <pair <int, int>, vector<pair <int, int>>, greater<pair <int, int>>> pq;

        pq.push({0, node1});

        while (!pq.empty()) {
            pair <int, int> hold = pq.top();
            pq.pop();

            if (hold.first <= dists[hold.second]) {
                for (auto it: gr[hold.second]) {
                    if (hold.first + it.second < dists[it.first]) {
                        dists[it.first] = hold.first + it.second;
                        pq.push({dists[it.first], it.first});
                    }
                }
            }
        }


        return dists[node2] == INT32_MAX ? -1: dists[node2];
    }
};

int main() {
    return 0;
}