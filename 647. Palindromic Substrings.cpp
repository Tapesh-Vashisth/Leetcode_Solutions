#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Shash {
    public: 
        vector <long long> prefixHash;
        vector <long long> ppow;
        long long m;
        long long p;

        Shash() {
            m = 1e9 + 9;
            p = 31;
            prefixHash = {0};
        }

        Shash(long long m) {
            this->m = m;
        }

        void calHashes(string & s) {
            long long power = 1;
            for (int i = 0; i < s.size(); i++) {
                ppow.push_back(power);

                prefixHash.push_back(((prefixHash[i] % m) + ((((s[i] - 'a' + 1) % m) * (ppow[i] % m)) % m)) % m);

                power = ((power % m) * (p % m)) % m;
            }
        }

        long long subHash(int low, int high) {
            return (((prefixHash[high] + m - prefixHash[low]) % m) * (ppow[ppow.size() - low - 1] % m)) % m;
        }
};

int countSubstrings(string s) {
    Shash sh, shrev;

    string rev = s;
    reverse(rev.begin(), rev.end());

    sh.calHashes(s);
    shrev.calHashes(rev);

    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j <= i; j++) {
            if (sh.subHash(j, i + 1) == shrev.subHash(s.size() - i - 1, s.size() - j)) {
                ans++;
            }
        }
    }

    return ans;
}


int main() {
    return 0;
}