#include <iostream>
#include <vector>
using namespace std;

int dac(vector <int> & nums, int low, int high) {
    if (low == high) {
        return 0;
    }

    int mid = (low + high)/2;

    int c1 = dac(nums, low, mid);
    int c2 = dac(nums, mid + 1, high);

    vector <int> doubled;
    for (int i = mid + 1; i <= high; i++) {
        doubled.push_back(nums[i] * 2);
    }

    int first = low;
    int second = 0;
    int c3 = 0;
    while (first <= mid && second < doubled.size()) {
        if (doubled[second] < nums[first]) {
            c3 += mid - first + 1;
            second++;
        } else {
            first++;
        }
    }

    vector <int> ret;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            ret.push_back(nums[left++]);
        } else {
            c3 += mid - left + 1;
            ret.push_back(nums[right++]);
        }
    }

    while (left <= mid) {
        ret.push_back(nums[left++]);
    }

    while (right <= high) {
        ret.push_back(nums[right++]);
    }

    for (int i = 0; i < ret.size(); i++) {
        nums[low + i] = ret[i];
    }

    return c1+c2+c3;
}

int reversePairs(vector<int>& nums) {
    int ans = dac(nums, 0, nums.size() - 1);
    return ans;
}

int main(){
    return 0;
}