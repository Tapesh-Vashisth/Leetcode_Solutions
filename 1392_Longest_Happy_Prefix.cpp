#include <iostream>
#include <vector>
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

string longestPrefix(string s) {
    DSHash sh;
    sh.computeHashes(s);
    
    int ansIndex = 0;

    for (int i = 0; i < s.size() - 1; i++) {
        if (sh.subHash(0, i + 1) == sh.subHash(s.size() - i - 1, s.size())) {
            ansIndex = i + 1;
        }
    }

    return s.substr(0, ansIndex);
}

int main() {
    return 0;
}