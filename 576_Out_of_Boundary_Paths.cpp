#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;

int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
    vector <vector <vector <long long>>> dp(maxMove + 1, vector <vector <long long>> (n, vector <long long> (m, 0)));

    vector <int> xs = {0, 0, 1, -1};
    vector <int> ys = {1, -1, 0, 0};
    for (int i = 1; i <= maxMove; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                for (int step = 0; step < xs.size(); step++) {
                    int holdx = j + xs[step];
                    int holdy = k + ys[step];

                    if (holdx >= 0 && holdx < n && holdy >= 0 && holdy < m) {
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][holdx][holdy]) % mod;
                    } else {
                        dp[i][j][k] = (dp[i][j][k] + 1) % mod;
                    }
                }
            }
        }
    }       

    return dp[maxMove][startRow][startColumn];
}

int main() {
    return 0;
}