#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool helper(vector <vector <int>> & graph, int root, vector <int> & hash) {
    if (hash[root] == 1) {
        return true;
    } 

    if (hash[root] == 0) {
        return false;
    }

    bool ret = true;

    for (int i = 0; i < graph[root].size(); i++) {
        bool hold = helper(graph, graph[root][i], hash);
        if (hold == false) {
            ret = false;
        }        
    }

    return ret;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector <int> hash(graph.size(), -1);

    for (int i = 0; i < graph.size(); i++) {
        if (hash[i] == -1) {
            hash[i] = helper(graph, i, hash);
        }
    }

    vector <int> ans;
    for (int i = 0; i < hash.size(); i++) {
        if (hash[i]) {
            ans.push_back(i);
        } 
    }

    return ans;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector <vector <int>> newGraph(graph.size());
    vector <int> indegrees(graph.size(), 0);

    for (int i = 0; i < graph.size(); i++) {
        for (auto it: graph[i]) {
            indegrees[i]++;
            newGraph[it].push_back(i);
        }
    }        

    vector <int> ans;
    set <pair <int, int>> store;
    for (int i = 0; i < indegrees.size(); i++) {
        store.insert({indegrees[i], i});
    }


    while (store.size() > 0 && (*store.begin()).first == 0) {
        pair <int, int> hold = (*store.begin());
        store.erase(store.begin());
        ans.push_back(hold.second);

        for (auto it: newGraph[hold.second]) {
            store.erase({indegrees[it], it});
            indegrees[it]--;
            store.insert({indegrees[it], it});
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}

int main() {
    return 0;
}