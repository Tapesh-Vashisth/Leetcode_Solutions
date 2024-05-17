#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    long long total = 0;
    for (int i = 0; i <= 1; i++) {
        total += nums[i];
    }   

    long long ans = -1;
    for (int i = 2; i < nums.size(); i++) {
        if (total > nums[i]) {
            ans = max(ans, total + nums[i]);
        }

        total += nums[i];
    }

    return ans;
}

int main() {
    return 0;
}