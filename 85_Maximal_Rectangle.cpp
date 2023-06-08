#include <iostream>
#include <vector>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    vector <vector <pair <int,int>>> dp (matrix.size() + 1, vector <pair <int,int>> (matrix[0].size() + 1, make_pair(0, 0)));

    int ans = 0;

    for (int i = 1; i < dp.size(); i++) {
        for (int j = 1; j < dp[i].size(); j++) {
            if (matrix[i - 1][j - 1]) {
                int height = min(dp[i][j - 1].second, dp[i - 1][j].second + 1);
                int width = min(dp[i][j - 1].first + 1, dp[i - 1][j].first);
                
                ans = max(ans, height * width);

                dp[i][j].first = dp[i - 1][j].first + 1;
                dp[i][j].second = dp[i][j - 1].second + 1;
            }
        }
    }

    return ans;
}

int main() {
    return 0;
}