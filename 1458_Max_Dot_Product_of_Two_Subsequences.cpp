#include <iostream>
#include <vector>
using namespace std;

int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    vector <vector <int>> dp (nums1.size(), vector <int> (nums2.size(), 0));

    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            int mx = nums1[i] * nums2[j];
            if (i - 1 >= 0) {
                mx = max(mx, dp[i - 1][j]);
            }

            if (j - 1 >= 0) {
                mx = max(mx, dp[i][j - 1]);
            }

            if (i - 1 >= 0 && j - 1 >= 0) {
                mx = max(mx, dp[i - 1][j - 1] + (nums1[i] * nums2[j]));
            }

            dp[i][j] = mx;
        }
    }         

    return dp[nums1.size() - 1][nums2.size() - 1];
}

int main() {
    return 0;
}