#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minPatches(vector<int>& nums, int n) {
    int index = 0;
    long long current = 0;

    int ans = 0;
    while (current < n) {
        if (index < nums.size()) {
            if (nums[index] <= current + 1) {
                current = nums[index] + current;
                index++;
            } else {
                ans++;
                current = current + (current + 1);
            }
        } else {
            ans++;
            current = current + (current + 1);
        }
    }

    return ans;
}

int main() {
    return 0;
}