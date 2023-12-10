#include <iostream>
#include <vector>
#include <map>
using namespace std;

int maxSubarrayLength(vector<int>& nums, int k) {
    map <int, int> store;
    
    int ans = 1;
    int low = 0;
    int bad = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (store[nums[i]] == k) {
            bad++;
        }
        
        store[nums[i]]++;
        
        while (bad > 0) {
            store[nums[low]]--;
            
            if (store[nums[low]] == k) {
                bad--;
            }
            low++;
        }
        
        ans = max(ans, i - low + 1);
    }
    
    return ans;
}

int main() {
    return 0;
}