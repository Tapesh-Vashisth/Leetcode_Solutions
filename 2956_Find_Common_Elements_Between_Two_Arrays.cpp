#include <iostream>
#include <vector>
using namespace std;

vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
    vector <int> hash1(101, 0);
    vector <int> hash2(101, 0);
    
    for (auto it: nums1) {
        hash1[it]++;
    }
    
    for (auto it: nums2) {
        hash2[it]++;
    }
    
    int ans1 = 0;
    for (auto it: nums1) {
        if (hash2[it] != 0) {
            ans1++;
        }
    }
    
    int ans2 = 0;
    for (auto it: nums2) {
        if (hash1[it] != 0) {
            ans2++;
        }
    }
    
    vector <int> ans = {ans1, ans2};
    
    return ans;
}

int main() {
    return 0;
}