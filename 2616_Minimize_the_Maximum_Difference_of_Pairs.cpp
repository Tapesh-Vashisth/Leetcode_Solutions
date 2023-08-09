#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool check(int mx, int p, vector <int> & nums) {
    int counter = 0;
    map <int, int> store;
    for (auto it: nums) {
        auto hold = store.lower_bound(it - mx);

        if (hold == store.end()) {
            store[it]++;
        } else {
            counter++;
            store[(*hold).first]--;

            if (store[(*hold).first] == 0) {
                store.erase(hold);
            }
        }
    }

    if (counter >= p) {
        return true;
    }

    return false;
}

int minimizeMax(vector<int>& nums, int p) {
    sort(nums.begin(), nums.end());
    int mx = INT32_MAX;

    int low = 0;
    int high = 0;
    for (auto it: nums) {
        high = max(high, it);
    }

    while (low <= high) {

        int mid = low + (high - low)/2;

        if (check(mid, p, nums)) {

            high = mid - 1;
            mx = min(mx, mid);
        } else {
            low = mid + 1;
        }
    }

    return mx == INT32_MAX ? 0: mx;
}

int main() {
    return 0;
}