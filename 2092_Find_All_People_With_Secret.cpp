#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;


vector <bool> secret;

void helper(int current, int currentTime, vector <int> & visited, vector <vector <pair <int, int>>> & graph) {
    if (currentTime < visited[current]) {
        visited[current] = currentTime;
        secret[current] = true;

        for (auto it: graph[current]) {
            if (it.second >= currentTime) {
                helper(it.first, it.second, visited, graph);
            }
        }
    }
}

vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    vector <vector <pair <int, int>>> graph(n);

    graph[0].push_back({firstPerson, 0});
    graph[firstPerson].push_back({0, 0});

    for (auto & it: meetings) {
        graph[it[0]].push_back({it[1], it[2]});
        graph[it[1]].push_back({it[0], it[2]});
    }

    secret.clear();
    secret = vector <bool> (n, false);

    vector <int> visited(n, INT32_MAX);
    helper(0, 0, visited, graph);

    vector <int> ans;
    for (int i = 0; i < n; i++) {
        if (secret[i]) {
            ans.push_back(i);
        }
    }

    return ans;
}

int main() {
    return 0;
}