#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const long long mod = 1e9 + 7;

int numFactoredBinaryTrees(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    map <int, int> store;

    int ans = 0;

    for (auto it: arr) {
        for (int i = 2; i * i <= it; i++) {
            if (it % i == 0) {
                int first = i;
                int second = it/i;

                if (store[first] != 0 && store[second] != 0) {
                    long long hold = (((long long)store[first] % mod) * ((long long)store[second] % mod)) % mod;
                    if (first != second) {
                        hold = (2 * hold) % mod;
                    }

                    store[it] = ((store[it] % mod) + (hold % mod)) % mod;
                    ans = ((ans % mod) + (hold % mod)) % mod;
                }
            }
        }    

        store[it] = (store[it] + 1) % mod;
        ans = (ans + 1) % mod;
    }
    
    return ans;
}

int main() {
    return 0;
}