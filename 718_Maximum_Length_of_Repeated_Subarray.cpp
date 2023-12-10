#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Shash {
    public: 
        vector <long long> prefixHash;
        vector <long long> ppow;
        long long m;
        long long p;

        Shash() {
            m = 1e9 + 9;
            p = 103;
            prefixHash = {0};
        }

        Shash(long long m) {
            this->m = m;
        }

        void calHashes(vector <int> & s) {
            long long power = 1;
            for (int i = 0; i <= 1000; i++) {
                ppow.push_back(power);
                power = ((power % m) * (p % m)) % m;
            }

            for (int i = 0; i < s.size(); i++) {
                prefixHash.push_back(((prefixHash[i] % m) + ((((s[i] + 1) % m) * (ppow[i] % m)) % m)) % m);
            }
        }

        long long subHash(int low, int high) {
            return (((prefixHash[high] + m - prefixHash[low]) % m) * (ppow[999 - low] % m)) % m;
        }
};



int findLength(vector<int>& nums1, vector<int>& nums2) {
    Shash sh1;
    Shash sh2;
    sh1.calHashes(nums1);
    sh2.calHashes(nums2);

    int ans = 0;
    for (int l = 1; l <= min(nums1.size(), nums2.size()); l++) {
        unordered_set <long long> store;
        for (int i = 0; i + l <= nums1.size(); i++) {
            long long hold = sh1.subHash(i, i + l);
            store.insert(hold);
        }

        for (int i = 0; i + l <= nums2.size(); i++) {
            long long hold = sh2.subHash(i, i + l);
            if (store.count(hold)) {
                ans = max(ans, l);
                break;
            }
        }

    }

    return ans;
}

int main() {
    return 0;
}