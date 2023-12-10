#include <iostream>
#include <vector>
using namespace std;


int countHelper(int current, int currentDigit, string & num, bool check, vector <vector <vector <int>>> & dp) {
    if (current == num.size() - 1) {
        dp[current][currentDigit][check] = 1;
        return 1;
    } 

    if (dp[current][currentDigit][check] != -1) {
        return dp[current][currentDigit][check];
    }

    int ret = 0;
    if (check) {
        for (int i = 0; i <= num[current + 1] - '0'; i++) {
            ret += countHelper(current + 1, i, num, (i == num[current + 1] - '0' ? true: false), dp);
        }
    } else {
        for (int i = 0; i <= 9; i++) {
            ret += countHelper(current + 1, i, num, check, dp);
        }
    }

    dp[current][currentDigit][check] = ret;

    return ret;
}

int helper(int current, string & num, bool check, vector <vector <vector <int>>> & store, vector <vector <int>> & dp) {
    if (current == num.size() - 1) {
        if (!check) {
            return 1;
        } else if (num[current] - '0' >= 1) {
            return 1;
        } else {
            return 0;
        }
    }

    if (dp[current][check] != -1) {
        return dp[current][check];
    }

    int ret = 0;
    if (check) {
        for (int i = 0; i <= num[current] - '0'; i++) {
            if (i == 1) {
                ret += helper(current + 1, num, (i == num[current] - '0') ? check: false, store, dp);

                if (i == num[current] - '0') {
                    ret += store[current][i][check];
                } else {
                    ret += store[current][i][false];
                }
            } else {
                ret += helper(current + 1, num, (i == num[current] - '0') ? check: false, store, dp);
            }
        }
    } else {
        for (int i = 0; i <= 9; i++) {
            if (i == 1) {
                ret += helper(current + 1, num, check, store, dp);

                ret += store[current][i][check];
            } else {
                ret += helper(current + 1, num, check, store, dp);
            }
        }
    }

    dp[current][check] = ret;

    return ret;
}

int countDigitOne(int n) {
    string num = to_string(n);

    vector <vector <vector <int>>> dp(num.size(), vector <vector <int>> (11, vector <int> (2, -1)));

    for (int i = 0; i <= num[0] - '0'; i++) {
        countHelper(0, i, num, (i == num[0] - '0' ? true: false), dp);
    }

    vector <vector <int>> dp2(num.size(), vector <int> (2, -1));

    return helper(0, num, true, dp, dp2);
}

int main() {
    return 0;
}