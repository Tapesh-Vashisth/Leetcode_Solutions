#include <iostream>
#include <vector>
using namespace std;

long long countSubarrays(vector<int>& nums, int k) {
    vector <int> store;

    int mx = 0;
    for (auto it: nums) {
        mx = max(mx, it);
    }       

    long long ans = 0; 

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == mx) {
            store.push_back(i);
        }

        if (store.size() >= k) {
            ans += (store[store.size() - k] + 1);
        }
    }

    return ans;
}

int main() {
    return 0;
}