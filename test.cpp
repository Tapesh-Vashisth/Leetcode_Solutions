#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const long long mod = 1e9 + 7;

long long helper(int left, int right, vector <int> & store, vector <vector <long long>> & dp) {
    if (left == right) {
        return store[left];
    }

    if (dp[left][right] != -1) {
        return dp[left][right];
    }

    long long mn = INT64_MAX;

    long long total = 0;
    for (int i = left; i <= right; i++) {
        total += store[i];
    }

    long long current = 0;
    for (int i = left; i < right; i++) {
        long long holdLeft = helper(left, i, store, dp);
        long long holdRight = helper(i + 1, right, store, dp);
        current += store[i];
        mn = min(mn, holdLeft + holdRight + ((i == left ? 0 : current)) + ((i + 1 == right) ? 0: (total - current)));   
    }

    dp[left][right] = mn;

    return mn;
}

int main() {
    int n;
    cin >> n;

    vector <int> store;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        store.push_back(x);
    }

    vector <vector <long long>> dp(n, vector <long long> (n, -1));

    cout << helper(0, n - 1, store, dp) << endl;
    
    return 0;
}