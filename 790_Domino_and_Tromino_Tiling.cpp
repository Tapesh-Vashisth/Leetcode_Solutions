#include <iostream>
#include <vector>
using namespace std;

int numTilings(int n) {
    vector <vector <int>> dp(n + 1, vector <int> (2, 0));

    dp[0][1] = 1;
    dp[1] = {0, 1};

    for (int i = 2; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 2][1] + dp[i - 1][0];
            } else if (j == 1) {
                dp[i][j] = 2 * dp[i - 1][0] + dp[i - 1][1] + dp[i - 2][1];
            }
        }
    }

    return dp[n][1];
}

int main() {
    return 0;
}