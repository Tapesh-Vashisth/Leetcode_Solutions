#include <iostream>
#include <vector>
using namespace std;


bool binary_search(vector <int> & nums, int target, int low, int high) {
    // cout << "binary " << low << " " << high << endl;
    while (low <= high) {
        int mid = low + (high - low)/2;

        if (nums[mid] > target) {
            high = mid - 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            return true;
        }
    }

    return false;
}

bool helper(vector <int> & nums, int target, int low, int high) {
    while (low <= high) {
        // cout << low << " " << high << endl;
        int mid = low + (high - low)/2;

        if (nums[mid] == target) {
            return true;
        } else if (nums[mid] == nums[low] && nums[mid] == nums[high]) {
            return (helper(nums, target, low, mid - 1) || helper(nums, target, mid + 1, high));
        } else if (nums[mid] < nums[low]) {
            bool decider = binary_search(nums, target, mid + 1, high);
            if (decider) return true;
            high = mid - 1;
        } else if (nums[mid] > nums[high]) {
            bool decider = binary_search(nums, target, low, mid - 1);
            if (decider) return true;
            low = mid + 1;
        } else if (nums[mid] == nums[low]) {
            bool decider = binary_search(nums, target, mid + 1, high);
            if (decider) return true;
            high = mid - 1;
        } else if (nums[mid] == nums[high]) {
            bool decider = binary_search(nums, target, low, mid - 1);
            if (decider) return true;
            low = mid + 1;
        } else {
            bool decider = binary_search(nums, target, low, high);
            return decider;
        }
    }

    return false;
}

bool search(vector<int>& nums, int target) {
    return helper(nums, target, 0, nums.size() - 1);      
}

int main() {
    return 0;
}