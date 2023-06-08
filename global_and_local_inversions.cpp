#include <iostream>
#include <vector>
using namespace std;

int countInversions(vector <int> &nums, int low, int high) {
    if (low - high == 0) {
        return 0;
    }

    int mid = (low+high)/2;
    int c1 = countInversions(nums, low, mid);
    int c2 = countInversions(nums, mid + 1, high);

    int leftp = low;
    int rightp = mid + 1;

    int c3 = 0;

    vector <int> ret;
    while (leftp <= mid && rightp <= high) {
        if (nums[leftp] <= nums[rightp]) {
            ret.push_back(nums[leftp++]);
        } else {
            c3 += mid - leftp + 1;
            ret.push_back(nums[rightp++]);
        }
    }

    while (leftp <= mid) {
        ret.push_back(nums[leftp++]);
    }

    while (rightp <= high) {
        ret.push_back(nums[rightp++]);
    }

    for (int i = 0; i < ret.size(); i++) {
        nums[low + i] = ret[i];
    }

    return c1 + c2 + c3;
}

bool isIdealPermutation(vector<int>& nums) {
    int local = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            local++;
        }
    }        
    
    int global = countInversions(nums, 0, nums.size() - 1);
    
    if (global == local) {
        return true;
    } else {
        return false;
    }
}

int main() {
    return 0;
}