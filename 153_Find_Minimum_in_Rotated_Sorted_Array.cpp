#include <iostream>
#include <vector>
using namespace std;

int helper(vector <int> & nums, int low, int high) {
    int mn = INT32_MAX;
    while (low <= high) {
        int mid = low + (high - low)/2;

        if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else {
            mn = min(mn, nums[mid]);
            high = mid - 1;
        }
    }

    return mn;
}

int findMin(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;

    return min(nums[0], helper(nums, low, high));
}

int main() {
    return 0;
}