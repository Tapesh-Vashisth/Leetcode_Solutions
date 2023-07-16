#include <iostream>
#include <vector>
using namespace std;

int maximumBeauty(vector<int>& nums, int k) {
    vector <int> hash (4e5 +100, 0);
    
    for (int i = 0; i < nums.size(); i++) {
        hash[(nums[i] - k) + 200000]++;
        hash[(nums[i] + k + 1) + 200000]--;
    }
    
    int ans = 0;
    int current = 0;
    for (int i = 0; i < hash.size(); i++) {
        current += hash[i];
        
        ans = max(ans, current);
    }
    
    return ans;
}

int main() {
    return 0;
}