#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long numberOfSubarrays(vector<int>& nums) {
    vector <int> maxRight(nums.size(), nums.size());        
    stack <int> store;

    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!store.empty() && nums[i] >= nums[store.top()]) {
            store.pop();
        }

        if (store.empty()) {
            maxRight[i] = nums.size();
        } else {
            maxRight[i] = store.top();
        }

        store.push(i);
    }

    map <int, vector <int>> keep;

    for (int i = 0; i < nums.size(); i++) {
        keep[nums[i]].push_back(i);
    }

    long long ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        int start = lower_bound(keep[nums[i]].begin(), keep[nums[i]].end(), i) - keep[nums[i]].begin();
        int end = lower_bound(keep[nums[i]].begin(), keep[nums[i]].end(), maxRight[i]) - keep[nums[i]].begin();

        ans += (end - start);
    }

    return ans;
}

int main() {
    return 0;
}