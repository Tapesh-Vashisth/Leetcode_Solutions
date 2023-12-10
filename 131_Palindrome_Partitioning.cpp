#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSHash {
    public:
        long long m1, m2;
        long long p1, p2;
        vector <long long> ppow1;
        vector <long long> ppow2;
        vector <long long> prefixHash1;
        vector <long long> prefixHash2;

        DSHash() {
            m1 = 1e9 + 7;
            m2 = 1e9 + 9;
            p1 = 31;
            p2 = 43;
            prefixHash1 = {0};
            prefixHash2 = {0};
        }

        DSHash(long long m1, long long m2, long long p1, long long p2) {
            this->m1 = m1;
            this->m2 = m2;
            this->p1 = p1;
            this->p2 = p2;
            prefixHash1 = {0};
            prefixHash2 = {0};
        }

        void computeHashes(string & s) {
            long long power1 = 1;
            long long power2 = 1;
            for (int i = 0; i < s.size(); i++) {
                ppow1.push_back(power1);
                ppow2.push_back(power2);

                prefixHash1.push_back((prefixHash1[i] + (((s[i] - 'A' + 1) * ppow1[i]) % m1)) % m1);
                prefixHash2.push_back((prefixHash2[i] + (((s[i] - 'A' + 1) * ppow2[i]) % m2)) % m2);

                power1 = ((power1 % m1) * (p1 % m1)) % m1;
                power2 = ((power2 % m2) * (p2 % m2)) % m2;
            }
        }

        pair <long long, long long> subHash(int low, int high) {
            long long first = (((prefixHash1[high] + m1 - prefixHash1[low]) % m1) * (ppow1[ppow1.size() - low - 1] % m1)) % m1;
            long long second = (((prefixHash2[high] + m2 - prefixHash2[low]) % m2) * (ppow2[ppow2.size() - low - 1] % m2)) % m2;

            return {first, second};
        }
};

int palindromicPartition(string str) {
    DSHash sh1, sh2;
    sh1.computeHashes(str);
    reverse(str.begin(), str.end());
    sh2.computeHashes(str);

    vector <int> dp(str.size() + 1, -1);
    dp[0] = 1;

    for (int i = 0; i < str.size(); i++) {
        int mn = INT32_MAX;

        // if (sh1.subHash(0, i + 1) == sh2.subHash(str.size() - i - 1, str.size())) {
        //     mn = 1;
        // }

        for (int j = 0; j < i + 1; j++) {
            if (dp[j] != -1) {
                if (sh1.subHash(j, i + 1) == sh2.subHash(str.size() - i - 1, str.size() - j)) {
                    mn = min(mn, dp[j] + 1);
                }
            }
        }

        dp[i] = mn == INT32_MAX ? -1 : mn;
    }

    return dp[str.size() - 1];
}

int main() {
    return 0;
}