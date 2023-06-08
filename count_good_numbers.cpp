#include <iostream>
using namespace std;

    const long long mod = 1e9 + 7;


    // a^b
    long long power(long long a, long long b) {
        int ans = 1;
        int res = a;
        while (b) {
            if (b&1) {
                ans = ((ans%mod)*(res%mod))%mod;
            }

            res = ((res%mod)*(res%mod))%mod;
            b = b >> 1;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long odds = n/2;
        long long evens = n - odds;
        long long c1 = power(4, odds);
        long long c2 = power(5, evens);

        return ((c1%mod)*(c2%mod))%mod;
    }

int main() {
    return 0;
}