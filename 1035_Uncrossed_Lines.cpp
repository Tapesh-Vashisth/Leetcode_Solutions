#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubsequence(vector <int> text1, vector <int> text2) {
    vector <vector <int>> dp(text1.size() + 1, vector <int>(text2.size() + 1, 0));

    for (int i = 1; i <= text1.size(); i++) {
        for (int j = 1; j <= text2.size(); j++) {
            dp[i][j] = max(dp[i - 1][j - 1] + (text1[i - 1] == text2[j - 1]), max(dp[i - 1][j], dp[i][j - 1]));
        }
    }

    return dp[text1.size()][text2.size()];
}

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    return longestCommonSubsequence(nums1, nums2);
}

int main() {
    return 0;
}