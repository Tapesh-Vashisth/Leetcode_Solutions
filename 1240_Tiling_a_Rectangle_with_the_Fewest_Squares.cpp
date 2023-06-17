#include <iostream>
#include <vector>
using namespace std;

int tilingRectangle(int n, int m) {
    vector <vector <int>> dp (n + 1, vector <int> (m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= min(i, j); k++) {
                // vertical 
                int first = dp[i][k] + dp[i][j - k];

                // horizontal 
                int second = dp[k][j] + dp[i - k][j];
            }
        }
    }

    return dp[n][m];
}

int main() {
    return 0;
}