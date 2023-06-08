#include <iostream>
#include <vector>
using namespace std;

int helper(vector <int> & nums, int i, int j) {
    if (i < j) {
        int ret = 0;

        for (int x = i; x < j; x++) {
            int hold = (nums[x] * nums[i - 1] * (nums[j + 1])) + helper(nums, i, x - 1);
            ret = max(hold, ret);
        }

        return ret;
    } else {
        return nums[i] * nums[i - 1] * nums[j + 1];
    }
}   

int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    return helper(nums, 1, nums.size() - 2);
}

int main() {
    return 0;
}