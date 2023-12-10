#include <iostream>
#include <vector>
using namespace std;

int subarraysWithKDistinct(vector<int>& nums, int k) {
    vector <int> hash(nums.size() + 1, 0);

    int ans = 0;

    int low = 0;
    int diff = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (hash[nums[i]] == 0) {
            diff++;
        }

        hash[nums[i]]++;

        if (diff < k) {

        } else if (diff > k) {
            while (diff > k) {
                if (hash[nums[low]] > 1) {
                    low++;
                } else {
                    diff--;
                    low++;
                }

                hash[nums[low]]--;
            }
            
            int hold = low;
            while (hash[nums[hold]] > 1) {
                hash[nums[hold]]--;
                hold++;
                ans++;
            }
        } else {
            int hold = low;
            while (hash[nums[hold]] > 1) {
                hash[nums[hold]]--;
                hold++;
                ans++;
            }
        }
    }

    return ans;
}

int main() {
    return 0;
}