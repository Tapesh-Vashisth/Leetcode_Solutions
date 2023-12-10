#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long minimumReplacement(vector<int>& nums) {
    int lim = nums[nums.size() - 1];

    sort(nums.begin(), nums.end());    
    long long ans = 0;
    for (int i = nums.size() - 2; i >= 0; i--) {
        if (nums[i] > lim) {
            int hold = (nums[i] / lim) - 1 + ((nums[i] % lim) != 0 ? 1: 0);

            int mx = (nums[i] % lim) != 0 ? (nums[i] % lim): lim;
            
            lim = nums[i]/(hold + 1);

            ans += hold;
        } else {
            lim = nums[i];
        }
    }        

    return ans;

}

int main() {
    return 0;
}