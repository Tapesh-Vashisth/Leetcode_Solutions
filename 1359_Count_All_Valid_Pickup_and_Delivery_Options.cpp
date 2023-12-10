#include <iostream>
#include <vector>
using namespace std;

long long mod = 1e9 + 7;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = ((res % mod) * (a % mod)) % mod;
        a = ((a % mod) * (a % mod)) % mod;
        b >>= 1;
    }
    return res % mod;
}

int countOrders(int n) {
    int ans = 1;
    int hold = n;

    while (hold) {
        int temp = 2 * hold - 1;

        ans = ((ans % mod) * ((((temp) % mod) * ((temp + 1) % mod) * binpow(2, mod - 2)) % mod)) % mod;
        hold--;
    }

    return ans;
}

int main() {
    return 0;
}