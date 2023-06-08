#include <iostream>
#include <vector>
using namespace std;

bool helper(vector <vector <int>> & graph, int root, vector <int> & first, vector <int> & second) {
    if (first[root]) {
        for (int i = 0; i < graph[root].size(); i++) {
            if (first[graph[root][i]]) {
                return false;
            }   

            second[graph[root][i]] = 1;
            bool temp = helper(graph, graph[root][i], first, second);

            if (!temp) {
                return false;
            }
        }
    } else {
        for (int i = 0; i < graph[root].size(); i++) {
            if (second[graph[root][i]]) {
                return false;
            }   

            first[graph[root][i]] = 1;
            bool temp = helper(graph, graph[root][i], first, second);

            if (!temp) {
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    vector <int> first(graph.size(), 0);
    vector <int> second(graph.size(), 0);
    for (int i = 0; i < graph.size(); i++) {
        if (first[i] || second[i]) {
            ;
        } else {
            first[i] = 1;
            bool check = helper(graph, i, first, second);

            if (!check) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    return 0;
}