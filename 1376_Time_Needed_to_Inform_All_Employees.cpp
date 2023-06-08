#include <iostream>
#include <vector>
using namespace std;


int helper(int current, vector <vector <int>> & graph, vector <int> & informTime) {
    int total = informTime[current];
    for (int i = 0; i < graph[current].size(); i++) {
        total += helper(graph[current][i], graph, informTime);
    }

    return total;
}

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    vector <vector <int>> graph(n);
    for (int i = 0; i < manager.size(); i++) {
        if (manager[i] != -1) {
            graph[manager[i]].push_back(i);
        }
    }

    return helper(headID, graph, informTime);
}

int main() {
    return 0;
}