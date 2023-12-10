#include <iostream>
#include <vector>
using namespace std;

int maxValueAfterReverse(vector<int>& nums) {
    int current = 0;

    vector <pair <int, int>> store;
    for (int i = 1; i < nums.size(); i++) {
        current += abs(nums[i] - nums[i - 1]);
        store.push_back({nums[i - 1], nums[i]});
    }        

    int ans = current;
    int maxminSoFar = min(store[store.size() - 1].first, store[store.size() - 1].second);
    int minmaxSoFar = max(store[store.size() - 1].first, store[store.size() - 1].second);
    for (int i = store.size() - 2; i >= 0; i--) {
        int mx = max(store[i].first, store[i].second);
        int mn = min(store[i].first, store[i].second);

        if (mx < maxminSoFar) {
            ans = max(ans, current + 2 * (maxminSoFar - mx));
        }

        if (mn > minmaxSoFar) {
            ans = max(ans, current + 2 * (mn - minmaxSoFar));
        }

        maxminSoFar = max(maxminSoFar, mn);
        minmaxSoFar = min(minmaxSoFar, mx);

    }


    for (int i = 1; i < nums.size() - 1; i++) {
        ans = max(ans, current - abs(nums[i] - nums[i + 1]) + abs(nums[0] - nums[i + 1]));
        ans = max(ans, current - abs(nums[nums.size() - 1 - i] - nums[nums.size() - 2 - i]) + abs(nums[nums.size() - 1] - nums[nums.size() - 2 - i]));
    }

    return ans;
}

int main() {
    return 0;
}