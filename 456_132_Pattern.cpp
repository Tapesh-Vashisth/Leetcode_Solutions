#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool find132pattern(vector<int>& nums) {
    set <pair <int, int>> store;

    for (int i = 1; i < nums.size(); i++) {
        store.insert({-nums[i], i});
    }

    int first = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        store.erase({-nums[i], i});

        int second = nums[i];

        auto pos = store.lower_bound({-nums[second] + 1, INT32_MIN});

        if (pos != store.end()) {
            int third = -(*pos).first;

            if (first < second && third < second && first < second) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    return 0;
}