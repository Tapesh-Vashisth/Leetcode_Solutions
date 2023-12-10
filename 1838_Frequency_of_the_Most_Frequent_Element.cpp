#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector <int> & nums, int k, int len) {
    int hold = 0;
    for (int i = 0; i < len; i++) {
        hold += (nums[len - 1] - nums[i]);
    }

    if (hold <= k) {
        return true;
    }

    for (int i = len; i < nums.size(); i++) {
        hold += (len - 1) * (nums[i] - nums[i - 1]);
        hold -= (nums[i - 1] - nums[i - len]);

        if (hold <= k) {
            return true;
        }
    }

    return false;
}

int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int low = 2;
    int high = nums.size();

    int ans = 1;
    while (low <= high) {
        int mid = low + (high - low)/2;

        if (check(nums, k, mid)) {
            ans = max(ans, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    return 0;
}