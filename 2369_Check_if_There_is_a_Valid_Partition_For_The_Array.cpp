#include <iostream>
#include <vector>
using namespace std;

bool validPartition(vector<int>& nums) {
    vector <bool> dp(nums.size() + 1, false);
    dp[0] = true;

    for (int i = 0; i < nums.size(); i++) {
        // check for 2 size
        if (i - 1 >= 0) {
            if (dp[i - 1] == true) {
                dp[i + 1] = (nums[i] == nums[i - 1]);
            }
        }

        if (!dp[i + 1]) {
            // check for 3 size
            if (i - 2 >= 0) {
                if (dp[i - 2] == true) {
                    dp[i + 1] = (nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]);

                    if (dp[i + 1]) continue;
                    dp[i + 1] = (nums[i - 2] + 1 == nums[i - 1] && nums[i - 1] + 1 == nums[i]);
                }
            } 
        }
    }


    return dp[nums.size()];
}

int main() {
    return 0;
}