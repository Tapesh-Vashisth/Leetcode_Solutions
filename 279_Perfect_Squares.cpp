#include <iostream>
#include <vector>
using namespace std;

bool squareOrNot(int x) {
    int low = 0;
    int high = x;

    while (low <= high) {
        int mid = (low + high)/2;

        if (mid * mid > x) {
            high = mid - 1;
        } else if (mid * mid < x) {
            low = mid + 1;
        } else {
            return true;
        }
    }

    return false;
}

int numSquares(int n) {
    vector <int> squares;
    vector <int> dp(n + 1, n);

    for (int i = 1; i <= n; i++) {
        if (squareOrNot(i)) {
            dp[i] = 1;
            squares.push_back(i);
        } else {
            for (auto it: squares) {
                dp[i] = min(dp[i],  1 + dp[i - it]);
            }
        }
    }

    return dp[n];
}

int main() {
    return 0;
}