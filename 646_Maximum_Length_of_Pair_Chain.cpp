#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> dp;

int helper(vector <vector <int>> & graph, int root) {
    int ret = 1;

    if (dp[root] != -1) {
        return dp[root];
    }

    for (int i = 0; i < graph[root].size(); i++) {
        int hold = 1 + helper(graph, graph[root][i]);
        ret = max(hold, ret);
    }

    dp[root] = ret;

    return ret;
}

static bool comparator (vector <int> & a, vector <int> & b) {
    if (a[1] < b[1]) {
        return true;
    } else {
        return false;
    }
} 

int findLongestChain(vector<vector<int>>& pairs) {
    vector <vector <int>> graph(pairs.size());

    sort(pairs.begin(), pairs.end(), comparator);

    for (int i = 0; i < pairs.size(); i++) {
        for (int j = i + 1; j < pairs.size(); j++) {
            if (pairs[i][1] < pairs[j][0]) {
                graph[i].push_back(j);
            }

            if (pairs[j][1] < pairs[i][0]) {
                graph[j].push_back(i);
            }
        }
    }


    dp = vector <int> (pairs.size(), -1);

    int ans = INT32_MIN;

    int hold = helper(graph, 0);
    ans = max(ans, hold);

    return ans;
}

int main() {
    return 0;
}