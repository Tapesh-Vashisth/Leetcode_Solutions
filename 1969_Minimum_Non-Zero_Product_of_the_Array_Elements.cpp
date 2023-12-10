#include <iostream>
using namespace std;


long long mod = 1e9 + 7;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = ((res % mod) * (a % mod)) % mod;
        }
        a = ((a % mod) * (a % mod)) % mod;
        b >>= 1;
    }
    return res;
}

int minNonZeroProduct(int p) {
    long long power = 1;
    for (int i = 0; i < p; i++) {
        power = power * 2;
    }        

    long long base = power - 2;

    long long ans = 1;

    ans = binpow(base, power/2 - 1);
    ans = ((ans % mod) * ((power - 1) % mod)) % mod;

    return ans;
}

int main() {
    return 0;
}