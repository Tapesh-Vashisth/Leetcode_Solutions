#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    set <pair <int, int>> store;

    for (int i = 0; i < min((int)nums.size(), indexDiff); i++) {
        int start = nums[i] - valueDiff;
        int end = nums[i] + valueDiff;

        auto posStart = store.lower_bound({start, INT32_MIN});

        if (posStart == store.end()) {
            ;
        } else {
            if ((*posStart).first >= start && (*posStart).first <= end) {
                return true;
            }     
        }

        store.insert({nums[i], i});
    }

    for (int i = indexDiff; i < nums.size(); i++) {
        int start = nums[i] - valueDiff;
        int end = nums[i] + valueDiff;

        auto posStart = store.lower_bound({start, INT32_MIN});

        if (posStart == store.end()) {
            ;
        } else {
            if ((*posStart).first >= start && (*posStart).first <= end) {
                return true;
            }     
        }

        store.erase({nums[i - indexDiff], i - indexDiff});
        store.insert({nums[i], i});
    }

    return false;
}

int main() {
    return 0;
}