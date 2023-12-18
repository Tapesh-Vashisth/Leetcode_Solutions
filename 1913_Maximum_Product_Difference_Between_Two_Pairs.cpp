#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProductDifference(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    return ((long long)nums[n - 1] * nums[n - 2]) - ((long long)nums[0] * nums[1]);        
}

int main() {
    return 0;
}