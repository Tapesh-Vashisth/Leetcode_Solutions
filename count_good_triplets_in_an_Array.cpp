#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    set <int> store;
    int n = nums1.size();
    vector <int> lesser1(n, 0);
    vector <int> lesser2(n, 0);
    vector <int> greater1(n, 0);
    vector <int> greater2(n, 0);
    // first less 
    for (int i = 0; i < nums1.size(); i++) {
        vector <int> hold;
        for (auto it: store) {
            hold.push_back(it);
        }

        int pos = lower_bound(hold.begin(), hold.end(), nums1[i]) - hold.begin();
        lesser1[nums1[i]] = pos;
        greater1[nums1[i]] = (n - nums1[i] - 1) - (i - pos);
        store.insert(nums1[i]);
    }

    // second less 
    store.clear();
    for (int i = 0; i < nums2.size(); i++) {
        vector <int> hold;
        for (auto it: store) {
            hold.push_back(it);
        }

        int pos = lower_bound(hold.begin(), hold.end(), nums2[i]) - hold.begin();
        lesser2[nums2[i]] = pos;
        greater2[nums2[i]] = (n - nums2[i] - 1) - (i - pos);
        store.insert(nums2[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += min(lesser1[i], lesser2[i]) * min(greater1[i], greater2[i]);
    }

    return ans;
}

int main() {
    return 0;
}