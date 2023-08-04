#include <iostream>
#include <vector>
using namespace std;


long long getithbit(long long x, long long i){
    long long bit = (long long)1 << (i - 1);
    return (x & bit ? 1 : 0);
}

long long clearithbit(long long x, long long i){
    long long bit = ~((long long)1 << (i - 1));
    return (x & bit);
}

long long setithbit(long long x, long long i){
    return (x | ((long long)1 << (i - 1)));
}


vector <int> dp;

int helper(int maxchosable, int state, int turns) {
    if (state == (1 << (maxchosable - 1))) {
        return 0;
    }

    if (dp[state] != -1) {
        return dp[state];
    }

    int mx = INT32_MIN;
    int mn = INT32_MAX;
    for (int i = 1; i <= maxchosable; i++) {
        if (!getithbit(state, i)) {
            int hold = helper(maxchosable, setithbit(state, i), turns + 1);
            mx = max(mx + i, hold);
            mn = min(mn, hold);
        }
    }


    int ret;
    if (turns % 2) {
        ret = mn;
    } else {
        ret = mx;
    }

    dp[state] = ret;

    return ret;
}


bool canIWin(int maxChoosableInteger, int desiredTotal) {
    dp = vector <int> (1 << maxChoosableInteger, -1);
    int hold = helper(maxChoosableInteger, 0, 0);

    if (hold >= desiredTotal) {
        return true;
    } else {
        return false;
    }
}

int main() {
    return 0;
}