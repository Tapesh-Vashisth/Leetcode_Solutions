#include <iostream>
#include <vector>
using namespace std;
 

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    long long current = 1;

    int low = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        current = current * nums[i];

        while (current >= k && low <= i) {
            current = current/nums[low];
            low++;    
        }

        ans += (i - low + 1);
    }        

    return ans;
}

int main() {
    return 0;
}