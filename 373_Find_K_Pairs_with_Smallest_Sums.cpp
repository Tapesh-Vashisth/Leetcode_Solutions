#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector <vector <int>> ans;

    priority_queue <vector <int>, vector<vector <int>>, greater<vector <int>>> store;
    for (int i = 0; i < min(nums1.size(), nums2.size()); i++) {
        store.push({nums1[i] + nums2[i], i, i});
    }

    int counter = 0;
    while (!store.empty() && counter < k) {
        vector <int> hold = store.top();
        store.pop();

        ans.push_back({nums1[hold[1]], nums2[hold[2]]});

        if (hold[1] == hold[2]) {
            if (hold[1] + 1 < nums1.size()) {
                store.push({nums1[hold[1] + 1] + nums2[hold[2]], hold[1] + 1, hold[2]});
            }

            if (hold[2] + 1 < nums2.size()) {
                store.push({nums1[hold[1]] + nums2[hold[2] + 1], hold[1], hold[2] + 1});
            }
        } else {
            if (hold[1] > hold[2]) {
                if (hold[1] + 1 < nums1.size()) {
                    store.push({nums1[hold[1] + 1] + nums2[hold[2]], hold[1] + 1, hold[2]});
                }
            } else {
                if (hold[2] + 1 < nums2.size()) {
                    store.push({nums1[hold[1]] + nums2[hold[2] + 1], hold[1], hold[2] + 1});
                }
            }
        }

        counter++;
    }

    return ans;
}

int main() {

    return 0;
}