#include <iostream>
#include <vector>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {
    vector <int> hash(nums.size() + 1, 0);

    hash[0] = 1;
    int current = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        current += nums[i];
        if (current - goal >= 0) {
            ans += hash[current - goal];
        }
        hash[current]++;
    }        


    return ans;
}

int main() {
    return 0;
}