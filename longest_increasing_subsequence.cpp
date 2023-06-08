#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector <int> hash(n, 0);
    vector <int> dp(n, 1);

    for (int i = 0; i < n; i++) {
        int mx = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] > nums[j]) {
                if (dp[j] > mx) { 
                    mx = dp[j];                    
                }
            }
        }

        dp[i] = mx + 1;
    }

    for (int i = 0; i < hash.size(); i++) {
        cout << hash[i] << " ";
    }
    cout << endl;
    int mx = 1;
    for (int i = 0; i < n; i++) {
        if (dp[i] > mx) {
            mx = dp[i];
        }
    }

    return mx;
}

int main() {
    return 0;
}