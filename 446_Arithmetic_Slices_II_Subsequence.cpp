#include <iostream>
#include <vector>
#include <map>
using namespace std;

int numberOfArithmeticSlices(vector<int>& nums) {
    long long n = nums.size();
    vector <map <long long, long long>> store(n);

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        ans++;
        for (int j = i - 1; j >= 0; j--) {
            int hold = store[j][(long long)nums[i] - nums[j]];
            ans += hold + 1;

            store[i][(long long)nums[i] - nums[j]] += hold + 1;
        }
    }

    
    return ans - n - ((n * (n - 1)) / 2);
}

int main() {
    return 0;
}