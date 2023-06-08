#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> dp;

int helper(int index, vector <int> & days, vector <int> & costs) {
    if (index >= days.size()) {
        return 0;
    }

    if (dp[days[index]] != -1) {
        return dp[days[index]];
    }

    int ind2 = lower_bound(days.begin(), days.end(), days[index] + 7) - days.begin();
    int ind3 = lower_bound(days.begin(), days.end(), days[index] + 30) - days.begin();

    int first = costs[0] + helper(index + 1, days, costs);
    int second = costs[1] + helper(index, days, costs);
    int third = costs[2] + helper(index, days, costs);

    dp[days[index]] = min(first, second, third);
    return dp[days[index]];
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    dp = vector <int> (366, -1);
    int ans = helper(0, days, costs);

    return ans;
}

int main() {
    return 0;
}