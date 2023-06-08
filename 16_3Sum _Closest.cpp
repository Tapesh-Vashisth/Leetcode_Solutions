#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int ans = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size(); i++) {
        int newTarget = target - nums[i];
        int low = i + 1;
        int high = nums.size() - 1;

        while (low < high) {
            int hold = nums[low] + nums[high];

            if (abs(target - (hold + nums[i])) < abs(target - ans)) {
                ans = hold + nums[i];
            }

            if (hold > newTarget) {
                high--;
            } else if (hold < newTarget) {
                low++;
            } else {
                ans = target;
                break;
            }
        }
    }

    return ans;
}

int main(){
    return 0;
}