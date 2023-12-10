#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int dfsHelper(int current, vector <int> & edges, vector <int> & ans) {
    if (ans[current] != 0) {
        return ans[current];
    }

    int hold = dfsHelper(edges[current], edges, ans);

    ans[current] = hold + 1;

    return hold + 1;
}

int cycleLengthHelper(int current, vector <int> & edges, vector <bool> & visited, vector <int> & whichCycle, int currentCycle) {
    if (visited[current]) {
        visited[current] = false;
        whichCycle[current] = currentCycle;
        return cycleLengthHelper(edges[current], edges, visited, whichCycle, currentCycle) + 1;
    } else {
        return 0;
    }
}

vector<int> countVisitedNodes(vector<int>& edges) {
    int n = edges.size();

    vector <int> indegrees(n, 0);

    for (int i = 0; i < n; i++) {
        indegrees[edges[i]]++;
    }        

    queue <int> store;

    for (int i = 0; i < n; i++) {
        if (indegrees[i] == 0) {
            store.push(i);
        }
    }        

    while (!store.empty()) {
        int hold = store.front();
        store.pop();

        indegrees[edges[hold]]--;

        if (indegrees[edges[hold]] == 0) {
            store.push(edges[hold]);
        }
    }

    vector <int> ans (n, 0);

    vector <int> whichCycle(n, -1);
    vector <int> cycleLenghts;

    int cycleCount = 0;
    for (int i = 0; i < n; i++) {
        if (indegrees[i] != 0 && whichCycle[i] == -1) {
            vector <bool> visited(n, true);
            int len = cycleLengthHelper(i, edges, visited, whichCycle, cycleCount);
            cycleLenghts.push_back(len);
            cycleCount++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (indegrees[i] != 0) {
            ans[i] = cycleLenghts[whichCycle[i]];
        }
    }

    for (int i = 0; i < n; i++) {
        if (indegrees[i] == 0) {
            dfsHelper(i, edges, ans);
        }
    }

    return ans;
}

int main() {
    return 0;
}