#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long mod = 1e9 + 7;

int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int low = 0;
    int high = nums.size() - 1;

    long long ans = 0;

    while (target - nums[low] > nums[low]) {
        while (nums[low] + nums[high] > target) {
            high--;
        }

        long long hold = 1;

        for (int i = 0; i < high - low; i++) {
            hold = hold * 2;
        }

        ans = ans + hold;

        low++;
    }


    return ans;
}

int main() {
    return 0;
}