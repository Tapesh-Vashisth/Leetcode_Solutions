#include <iostream>
#include <vector>
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

int main() {
    return 0;
}