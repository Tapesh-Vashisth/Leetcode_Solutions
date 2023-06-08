#include <iostream>
#include <vector>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    vector <vector <int>> dp(matrix.size() + 1, vector <int> (matrix[0].size() + 1, 0));

    int ans = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j]) {
                int hold = min(dp[i][j], min(dp[i][j + 1], dp[i + 1][j]));
                ans = max(hold + 1, ans);
                dp[i + 1][j + 1] = hold + 1;
            }
        }
    }

    return ans*ans;
}

int main() {
    return 0;
}