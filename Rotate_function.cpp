#include <bits/stdc++.h>
using namespace std;

    int maxRotateFunction(vector<int>& nums) {
        int total = 0;
        int indexTotal = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
            indexTotal += nums[i] * i;
        }

        int ans = indexTotal;
        for (int i = 1; i < nums.size(); i++) {
            indexTotal = indexTotal + total - nums.size() * nums[nums.size() - 1];
            ans = max(ans, indexTotal);
        }        
        
        return ans;
    } 

int main(){
    return 0;
}