#include <iostream>
#include <vector>
using namespace std;

        
double champagneTower(int poured, int query_row, int query_glass) {
    vector <vector <double>> dp(query_row + 1, vector <double> (query_row + 1, 0));

    dp[0][0] = poured;

    for (int i = 1; i <= query_row; i++) {
        for (int j = 0; j <= i; j++) {
            double total = 0;
            if (j - 1 >= 0) {
                total += ((dp[i - 1][j - 1] - 1) <= 0 ? 0 : (dp[i - 1][j - 1] - 1))/2.0;
            }

            total += ((dp[i - 1][j] - 1) <= 0 ? 0 : (dp[i - 1][j] - 1))/2.0;

            dp[i][j] = total;
        }
    }

    return dp[query_row][query_glass] >= 1 ? 1 : dp[query_row][query_glass];
}

int main() {
    return 0;
}