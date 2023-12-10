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

bool checkPalindrome(string & s) {
    int low = 0;
    int high = s.size() - 1;

    while (low < high) {
        if (s[low] != s[high]) {
            return false;
        }

        low++;
        high--;
    }

    return true;
}

string shortestPalindrome(string s) {
    int n = s.size();

    if (checkPalindrome(s)) {
        return s;
    }

    Shash sh1, sh2;

    sh1.calHashes(s);
    reverse(s.begin(), s.end());
    sh2.calHashes(s);
    reverse(s.begin(), s.end());

    string ans;
    int holdmin = n;
    for (int i = 0; 2 * i + 2 <= s.size(); i++) {
        // take - (0, i + 1) to (n - (2*i + 2), n - (i + 1)) 
        long long first = sh1.subHash(0, i + 1);
        long long second = sh2.subHash(n - (2*i + 2), n - (i + 1));

        if (first == second) {
            holdmin = min(holdmin, n - (2*i + 2));
        }

        // not take - (0, i) to (n - (2*i + 1), n - (i + 1))
        first = sh1.subHash(0, i);
        second = sh2.subHash(n - (2*i + 1), n - (i + 1));

        if (first == second) {
            holdmin = min(holdmin, n - (2*i + 1));
        }
    }


    for (int i = 0; i < holdmin; i++) {
        ans.push_back(s[s.size() - 1 - i]);
    }

    ans.insert(ans.end(), s.begin(), s.end());

    return ans;
}

int main() {
    return 0;
}