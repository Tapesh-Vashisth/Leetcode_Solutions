#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class DSU {
    public: 
        vector <int> parents;

        DSU(int n) {
            for (int i = 0; i < n; i++) {
                parents.push_back(i);
            }
        }

        int findParent(int x) {
            if (parents[x] == x) {
                return x;
            }

            int hold = findParent(parents[x]);
            parents[x] = hold;
            return hold;    
        }

        bool U(int first, int second) {
            int firstParent = findParent(first);
            int secondParent = findParent(second);

            if (firstParent == secondParent) {
                return false;
            }

            parents[firstParent] = secondParent;
            return true; 
        }
};

int minCostConnectPoints(vector<vector<int>>& points) {
    priority_queue <pair <int, pair <int, int>>, vector<pair <int, pair <int, int>>>, greater<pair <int, pair <int, int>>>> pq;


    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            pq.push({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), {i, j}});            
        }
    }

    int ans = 0;
    DSU dsu(points.size());
    while (!pq.empty()) {
        pair <int, pair <int, int>> hold = pq.top();
        pq.pop();
        if (dsu.U(hold.second.first, hold.second.second)) {
            ans += hold.first;
        }
    }

    return ans;
}

int main() {
    return 0;
}