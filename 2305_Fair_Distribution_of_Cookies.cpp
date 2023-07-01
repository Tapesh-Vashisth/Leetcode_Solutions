#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int helper(vector <int> & cookies, int k, vector <int> & store, int index) {
    if (index >= cookies.size()) {
        int mx = INT32_MIN;

        for (auto it: store) {
            mx = max(mx, it);
        }

        return mx;
    }

    int mn = INT32_MAX;

    for (int i = 0; i < k; i++) {
        store[i] += cookies[index];
        mn = min(mn, helper(cookies, k, store, index + 1));
        store[i] -= cookies[index];
    }

    return mn;
}

int distributeCookies(vector<int>& cookies, int k) {
    vector <int> store(k, 0);

    return helper(cookies, k, store, 0);
}

int main() {
    return 0;
}