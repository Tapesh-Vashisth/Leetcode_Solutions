#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool check(long long cons) {
    string hold = to_string(cons);
    int low = 0;
    int high = hold.size() - 1;

    while (low < high) { 
        if (hold[low] != hold[high]) {
            return false;
        }

        high--;
        low++;
    }

    return true;
}

int helper(int l, int h, long long low, long long high, string & cons) {
    if (l > h) {
        long long hold = stol(cons);
        long long holdsquare = hold * hold;
        if (holdsquare >= low && holdsquare <= high) {
            return check(holdsquare);
        } else {
            return 0;
        }
    }

    int ret = 0;

    if (l == 0) {
        for (int i = 1; i <= 9; i++) {
            cons[l] = '0' + i;
            cons[h] = '0' + i;
            ret += helper(l + 1, h - 1, low, high, cons);
        }
    } else {
        for (int i = 0; i <= 9; i++) {
            cons[l] = '0' + i;
            cons[h] = '0' + i;
            ret += helper(l + 1, h - 1, low, high, cons);
        }
    }

    return ret;
}

int superpalindromesInRange(string left, string right) {
    long long low = stol(left);
    long long high = stol(right);

    int ans = 0;

    for (int i = 1; i <= 9; i++) {
        string hold;
        hold.resize(i);

        int l = 0;
        int h = i - 1;
        
        ans += helper(l, h, low, high, hold);
    }

    return ans;
}

int main() {
    return 0;
}