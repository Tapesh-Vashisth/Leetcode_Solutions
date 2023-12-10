#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    priority_queue <pair <int, pair <int, int>>, vector<pair <int, pair <int, int>>>, greater<pair <int, pair <int, int>>>> pq;


    vector <vector <int>> minEffort(heights.size(), vector <int> (heights[0].size(), INT32_MAX));
    pq.push({0, {0, 0}});

    vector <int> xs = {1, -1, 0, 0};
    vector <int> ys = {0, 0, 1, -1};
    while (!pq.empty()) {
        pair <int, pair <int, int>> hold = pq.top();
        pq.pop();

        if (hold.first <= minEffort[hold.second.first][hold.second.second]) {
            for (int i = 0; i < 4; i++) {
                int holdx = hold.second.first + xs[i];
                int holdy = hold.second.second + ys[i];

                if (holdx >= 0 && holdx < heights.size() && holdy >= 0 && holdy < heights[0].size()) {
                    int decider = max(hold.first, abs(heights[holdx][holdy] - heights[hold.second.first][hold.second.second]));

                    if (decider < minEffort[holdx][holdy]) {
                        minEffort[holdx][holdy] = decider;
                        pq.push({decider, {holdx, holdy}});
                    }
                }
            }
        }
    }

    return minEffort[heights.size() - 1][heights[0].size() - 1];
}

int main() {
    return 0;
}