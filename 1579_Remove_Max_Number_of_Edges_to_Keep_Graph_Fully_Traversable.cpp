#include <iostream>
#include <vector>
using namespace std;

int parent(vector <int> & parents, int child) {
    if (parents[child] == child) {
        return child;
    }

    parents[child] = parent(parents, parents[child]);

    return parents[child];
}

int U(vector <int> & parents, int first, int second) {
    int firstParent = parent(parents, first);
    int secondParent = parent(parents, second);

    if (firstParent != secondParent) {
        parents[firstParent] = secondParent;
        parents[first] = secondParent;
        parents[second] = secondParent;
        return 0;
    } else {
        return 1;
    }
}

int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    vector <int> alice(n + 1, 0);
    vector <int> bob(n + 1, 0);


    for (int i = 0; i <= n; i++) {
        alice[i] = i;
        bob[i] = i;
    }

    int ans = 0;

    for (int i = 0; i < edges.size(); i++) {
        if (edges[i][0] == 3) {
            int first = U(alice, edges[i][1], edges[i][2]);
            int second = U(bob, edges[i][1], edges[i][2]);

            ans += first || second;
        }
    }

    for (int i = 0; i < edges.size(); i++) {
        if (edges[i][0] == 1) {
            ans += U(alice, edges[i][1], edges[i][2]);
        } else if (edges[i][0] == 2) {
            ans += U(bob, edges[i][1], edges[i][2]);
        }
    }

    bool decider = false;
    int aliceMainParent = parent(alice, 1);
    int bobMainParent = parent(bob, 1);
    for (int i = 1; i < n + 1; i++) {
        if (parent(alice, i) != aliceMainParent || parent(bob, i) != bobMainParent) {
            decider = true;
            break;
        } 
    }

    if (decider) {
        return -1;
    }

    return ans;
}

int main() {
    return 0;
}