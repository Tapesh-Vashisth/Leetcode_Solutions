#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;


int countHomogenous(string s) {
    int ans = 0;

    int prev = -1;
    for (int i = 0; i < s.size(); i++) {
        if (i != 0 && s[i] != s[i - 1]) {
            prev = i - 1;
        }

        ans = (ans + (((i - prev) % mod) + mod) % mod) % mod;
    }        

    return ans % mod;
}

int main() {
    return 0;
}