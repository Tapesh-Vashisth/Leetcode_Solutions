#include <iostream>
#include <vector>
using namespace std;

int helper(vector <int> & nums, int low, int high) {
    int mn = INT32_MAX;
    while (low <= high) {
        int mid = low + (high - low)/2;

        mn = min(mn, nums[mid]);
        if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else if (nums[mid] < nums[high]) {
            high = mid - 1;
        } else {
            int hold = min(helper(nums, low, mid - 1), helper(nums, mid + 1, high));    
            mn = min(mn, hold);
            break;
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