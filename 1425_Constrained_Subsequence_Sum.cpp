#include <iostream>
#include <vector>
#include <set>
using namespace std;

int constrainedSubsetSum(vector<int>& nums, int k) {
    set <pair <int, int>> store;

    int low = 0;
    int ans = INT32_MIN;

    vector <int> keep(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
        if (i - low > k) {
            store.erase({-keep[low], low});
            low++;
        }

        if (store.size() == 0) {
            keep[i] = nums[i];
        } else {
            keep[i] = max(0, - (*store.begin()).first) + nums[i];
        }

        ans = max(ans, keep[i]);

        store.insert({-keep[i], i});
    }

    return ans;
}

int main() {
    return 0;
}