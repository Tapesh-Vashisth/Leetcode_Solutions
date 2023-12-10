#include <iostream>
#include <vector>
using namespace std;

int integerBreak(int n) {
    vector <vector <int>> dp(n, vector <int> (n, 0));


    for (int i = 0; i < n; i++) {
        dp[i][0] = i + 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            int temp = 0;
            for (int k = 0; k < i; k++) {
                temp = max(temp, dp[k][j - 1] * (i - k));
            }

            dp[i][j] = temp;
        }
    }

    for (auto it: dp) {
        for (auto it2: it) {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}

int main() {
    return 0;
}