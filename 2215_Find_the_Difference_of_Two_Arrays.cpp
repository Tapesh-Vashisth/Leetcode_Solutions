#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector <int> hash1(2001, 0);
    vector <int> hash2(2001, 0);

    vector <vector <int>> ans(2, vector <int> ());

    for (auto & it: nums1) {
        hash1[it + 1000] = 1;
    }

    for (auto & it: nums2) {
        hash2[it + 1000] = 1;
        if (hash1[it + 1000] != 1) {
            ans[1].push_back(it);
            hash1[it + 1000] = 1;
        }
    }

    for (auto & it: nums1) {
        if (hash2[it + 1000] != 1) {
            ans[0].push_back(it);
            hash2[it + 1000] = 1;
        }
    }

    return ans;
}

int main() {
    return 0;
}