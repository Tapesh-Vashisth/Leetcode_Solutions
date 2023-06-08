#include <iostream>
#include <vector>
using namespace std;

int findParent(vector <int> & parents, int x) {
    if (parents[x] != x) {
        int hold = findParent(parents, parents[x]);
        parents[x] = hold;
        return hold;
    }

    return x;
}

void U(vector <int> & parents, int x, int y) {
    int first = findParent(parents, x);
    int second = findParent(parents, y);

    if (first != second) {
        parents[first] = second; 
    }
}


int findCircleNum(vector<vector<int>>& isConnected) {
    vector <int> parents(isConnected.size());
    for (int i = 0; i < isConnected.size(); i++) {
        parents[i] = i;
    }            

    for (int i = 0; i < isConnected.size(); i++) {
        for (int j = 0; j < isConnected[i].size(); j++) {
            if (isConnected[i][j]) {
                U(parents, i, j);
            }
        }
    }


    int ans = 0;

    for (int i = 0; i < parents.size(); i++) {
        ans += parents[i] == i;
    } 

    return ans;
}

int main() {
    return 0;
}