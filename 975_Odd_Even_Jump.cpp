#include <iostream>
#include <vector>
#include <set>
using namespace std;

int oddEvenJumps(vector<int>& arr) {
    // even jumps 
    set <pair <int, int>> store;
    vector <int> even(arr.size(), -1);

    for (int i = arr.size() - 1; i >= 0; i--) {
        auto it = store.lower_bound({-arr[i], -1});

        if (it != store.end()) {
            even[i] = (*it).second;
        }

        store.insert({-arr[i], i});
    }

    // odd jumps    
    store.clear();
    vector <int> odd(arr.size(), -1);

    for (int i = arr.size() - 1; i >= 0; i--) {
        auto it = store.lower_bound({arr[i], -1});

        if (it != store.end()) {
            odd[i] = (*it).second;
        }

        store.insert({arr[i], i});
    }

    vector <vector <int>> dp(arr.size(), vector <int> (2, 0));
    for (int i = 0; i < arr.size(); i++) {
        dp[i][0] = 1;
    }

    for (int i = 0; i < arr.size(); i++) {
        // odd move 
        if (odd[i] != -1) {
            dp[odd[i]][1] += dp[i][0];
        }

        // even move
        if (even[i] != -1) {
            dp[even[i]][0] += dp[i][1];
        } 
    }

    return dp[arr.size() - 1][0] + dp[arr.size() - 1][1];
}

int main() {
    return 0;
}