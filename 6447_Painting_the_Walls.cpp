#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector <vector <long long>> dp;

long long helper(vector <int> & cost, vector <int> & time, int index, int counterplustotal) {
    if (counterplustotal >= cost.size()) {
        return 0;
    }

    if (index >= cost.size()) {
        return INT32_MAX;
    }
    
    if (dp[index][counterplustotal] != -1) {
        return dp[index][counterplustotal];
    }

    long long hold = INT32_MAX;

    // take     
    long long take = helper(cost, time, index + 1, counterplustotal + time[index] + 1) + cost[index];

    // not take 
    long long notTake = helper(cost, time, index + 1, counterplustotal);

    hold = min(take, notTake);
    
    dp[index][counterplustotal] = hold;

    return hold;
}

int paintWalls(vector<int>& cost, vector<int>& time) {
    dp = vector <vector <long long>> (cost.size(), vector <long long> (cost.size(), -1));
    long long ans = helper(cost, time, 0, 0);
    return ans;
}

int main() {
    return 0;
}