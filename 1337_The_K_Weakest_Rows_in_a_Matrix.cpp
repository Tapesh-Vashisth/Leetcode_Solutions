#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector <int> ans;
    priority_queue <pair <int, int>, vector<pair <int, int>>, greater<pair <int, int>>> pq;
    for (int i = 0; i < mat.size(); i++) {
        int ones = 0;
        for (int j = 0; j  < mat[i].size(); j++) {
            ones += mat[i][j] == 1 ? 1 : 0;
        }

        pq.push({ones, i});
    }        

    while (k) {
        ans.push_back(pq.top().second);
        pq.pop();
        k--;
    }

    return ans;
}

int main() {
    return 0;
}