#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int minOperations(vector<int>& nums) {
    set <int> store;
    for (auto it: nums) {
        store.insert(it);
    }

    vector <int> keep;
    for (auto it: store) {
        keep.push_back(it);
    }

    int ans = nums.size();

    for (int i = 0; i < keep.size(); i++) {
        int pos = upper_bound(keep.begin(), keep.end(), keep[i] + nums.size() - 1) - keep.begin();
        ans = min(ans, (int)nums.size() - (pos - i));
    }

    return ans;
}

int main() {
    return 0;
}