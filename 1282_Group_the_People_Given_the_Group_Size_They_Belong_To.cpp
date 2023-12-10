#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    vector <pair <int, int>> store;
    for (int i = 0; i < groupSizes.size(); i++) {
        store.push_back({groupSizes[i], i});
    }

    sort(store.begin(), store.end());

    vector <vector <int>> ans;

    ans.push_back({store[0].second});
    for (int i = 1; i < store.size(); i++) {
        if (store[i].first != store[i - 1].first || store[i].first == ans[ans.size() - 1].size()) {
            ans.push_back({store[i].second});
        } else {
            ans[ans.size() - 1].push_back(store[i].second);
        }
    }

    return ans;
}

int main() {
    return 0;
}