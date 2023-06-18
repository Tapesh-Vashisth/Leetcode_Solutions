#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map <string, int> dp;
    
int helper(vector <int> & cost, vector <int> & time, string & visited, int counter, int total) {
    if (total >= cost.size() - counter) {
        return 0;
    }
    
    if (dp[visited] != 0) {
        return dp[visited];
    }

    int hold = INT32_MAX;

    for (int i = 0; i < cost.size(); i++) {
        if (visited[i] == '0') {
            visited[i] = '1';
            hold = min(hold, helper(cost, time, visited, counter + 1, total + time[i]) + cost[i]);
            visited[i] = '0';
        }
    }
    
    dp[visited] = hold;

    return hold;
}

int paintWalls(vector<int>& cost, vector<int>& time) {
    string visited = "";
    for (auto it: cost) {
        visited.push_back('0');
    }
    int ans = helper(cost, time, visited, 0, 0);
    
    return ans;
}

int main() {
    return 0;
}