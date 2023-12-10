#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int reductionOperations(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int prev = nums[nums.size() - 1];
    int counter = 1;
    int ans = 0;
    for (int i = nums.size() - 2; i >= 0; i--) {
        if (nums[i] != prev) {
            ans += counter;
        }

        counter++;
    }

    return ans;
}

int main() {
    return 0;
}