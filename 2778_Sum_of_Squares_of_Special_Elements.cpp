#include <iostream>
#include <vector>
using namespace std;

int sumOfSquares(vector<int>& nums) {
    int ans = 0;
    for (int i = 1; i <= nums.size(); i++) {
        if (nums.size() % i == 0) {
            ans += nums[i - 1] * nums[i - 1];
        }
    } 
    
    return ans;
}

int main() {
    return 0;
}