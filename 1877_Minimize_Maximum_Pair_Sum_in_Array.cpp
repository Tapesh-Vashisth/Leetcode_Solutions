#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int low = 0;
    int high = nums.size() - 1;

    int ans = 0;
    while (low < high) {
        ans = max(ans, nums[low] + nums[high]);

        low++;
        high--;
    }        

    return ans;
}

int main() {
    return 0;
}