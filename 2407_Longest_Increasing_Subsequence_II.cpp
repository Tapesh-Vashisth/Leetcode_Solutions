#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums, int k) {
    vector <int> store;

    for (int i = 0; i < nums.size(); i++) {
        int pos = lower_bound(store.begin(), store.end(), nums[i]) - store.begin();

        if (pos == store.size()) {
            if (pos == 0) {
                store.push_back(nums[i]);
            } else if (nums[i] - store[pos - 1] <= k) {
                store.push_back(nums[i]);
            }
        } else {
            if (pos == 0) {
                if (store[pos + 1] - nums[i] <= k) {
                    store[pos] = nums[i];
                }
            } else {
                if (store[pos + 1] - nums[i] <= k && nums[i] -  store[pos - 1] <= k) {
                    store[pos] = nums[i];
                }
            }
        }
    }

    return store.size();
}

int main() {
    return 0;
}