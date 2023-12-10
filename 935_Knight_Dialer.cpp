#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;

int helper(int current, int number, vector <vector <int>> & graph, vector <vector <int>> & dp) {
    if (current == 0) {
        return 1;
    }

    if (dp[current][number] != -1) {
        return dp[current][number];
    }

    long long ret = 0;

    for (auto it: graph[number]) {
        ret = (ret + helper(current - 1, it, graph, dp)) % mod;
    }


    dp[current][number] = ret;

    return ret;
}

int knightDialer(int n) {
    vector <vector <int>> graph = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {0, 3, 9},
        {},
        {0, 1, 7},
        {2, 6},
        {1, 3},
        {2, 4},
    };       

    vector <vector <int>> dp(n + 1, vector <int> (10, -1)); 

    long long ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans = ((ans % mod) + (helper(n - 1, i, graph, dp) % mod)) % mod;
    }

    return ans;
}

int main() {
    return 0;
}