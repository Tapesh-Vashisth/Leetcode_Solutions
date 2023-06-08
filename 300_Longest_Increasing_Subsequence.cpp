#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector <int> store;
    for (int i = 0; i < nums.size(); i++) {
        int pos = lower_bound(store.begin(), store.end(), nums[i]) - store.begin();
        if (pos == store.size()) {
            store.push_back(nums[i]);
        } else {
            store[pos] = nums[i];
        }
    }       
} 

int lengthOfLIS(vector<int>& nums) {
            
}

int main() {
    return 0;
}