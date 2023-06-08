#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // kahn's algorithm 
    vector <int> indegree(numCourses, 0);
    
    vector <vector <int>> gh(numCourses);

    for (int i = 0; i < prerequisites.size(); i++) {
        gh[prerequisites[i][1]].push_back(prerequisites[i][0]);
        indegree[prerequisites[i][0]]++;
    }       

    queue <int> store;     

    for (int i = 0; i < indegree.size(); i++) {
        if (indegree[i] == 0) {
            store.push(i);
        }
    }

    vector <int> topo;

    while (!store.empty()) {
        int hold = store.front();
        store.pop();
        topo.push_back(hold);

        for (int i = 0; i < gh[hold].size(); i++) {
            indegree[gh[hold][i]]--;
            if (indegree[gh[hold][i]] == 0) {
                store.push(gh[hold][i]);
            }
        }
    }

    if (topo.size() < numCourses) {
        return {};
    }

    return topo;
}

int main() {
    return 0;
}