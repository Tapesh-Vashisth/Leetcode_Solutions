#include <iostream>
#include <vector>
#include <set>
using namespace std;

int minExtraChar(string s, vector<string>& dictionary) {
    set <string> store;
    for (auto & it: dictionary) {
        store.insert(it);
    }

    vector <int> dp = {0};

    for (int i = 0; i < s.size(); i++) {
        int mn = INT32_MAX;
        for (int j = i; j >= 0; j--) {
            if (store.find(s.substr(j, i - j + 1)) == store.end()) {
                mn = min(mn, dp[j] + (i - j + 1));
            } else {
                mn = min(mn, dp[j]);
            }
        }

        dp.push_back(mn);
    }

    return dp[s.size()];
}

int main() {
    return 0;
}