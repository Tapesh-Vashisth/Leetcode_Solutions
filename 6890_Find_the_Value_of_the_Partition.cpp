#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findValueOfPartition(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int ans = INT32_MAX;
    for (int i = 1; i < nums.size(); i++) {
        ans = min(ans, abs(nums[i] - nums[i - 1]));
    }

    return ans;
}

int main() {
    return 0;
}