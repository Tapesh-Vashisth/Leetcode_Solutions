#include <iostream>
#include <vector>
using namespace std;

int findLengthOfLCIS(vector<int>& nums) {
    int prev = INT32_MIN;

    int ans = 0;
    int cur = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > prev) {
            cur++;
            ans = max(ans, cur);
        } else {
            cur = 1;
        }

        prev = nums[i];
    }

    return ans;
}

int main() {
    return 0;
}