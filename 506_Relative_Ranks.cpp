#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {
    vector <string> ans(score.size());

    vector <pair <int, int>> store;
    for (int i = 0; i < score.size(); i++) {
        store.push_back({score[i], i});
    }

    sort(store.begin(), store.end());

    for (int i = store.size() - 1; i >= 0; i--) {
        if (i == store.size() - 1) {
            ans[store[i].second] = "Gold Medal";
        } else if (i == store.size() - 2) {
            ans[store[i].second] = "Silver Medal";
        } else if (i == store.size() - 3) {    
            ans[store[i].second] = "Bronze Medal";
        } else {
            ans[store[i].second] = to_string(store.size() - i);
        }
    }

    return ans;
}

int main() {
    return 0;
}