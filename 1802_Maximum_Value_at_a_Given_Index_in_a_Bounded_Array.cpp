#include <iostream>
using namespace std;

bool check(long long n, long long index, long long maxSum, long long mx) {
    long long minSumLeft = (index > mx - 1 ? index - (mx - 1): 0) + ((mx * (mx - 1))/2) - (index < mx - 1 ? ((mx - 1 - index) * (mx - index))/2  : 0);
    index = n - index - 1;
    long long minSumRight = (index > mx - 1 ? index - (mx - 1): 0) + ((mx * (mx - 1))/2) - (index < mx - 1 ? ((mx - 1 - index) * (mx - index))/2  : 0);


    if (minSumLeft + minSumRight + mx > maxSum) {
        return false;
    }

    return true;
}

int maxValue(int n, int index, int maxSum) {
    long long low = 1;
    long long high = maxSum;

    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low)/2;

        if (check(n, index, maxSum, mid)) {
            ans = max(ans, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }        

    return ans;
}

int main() {
    return 0;
}