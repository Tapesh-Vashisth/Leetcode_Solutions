#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int shortestSubarray(vector<int>& nums, int k) {
    map <long long, long long> mapped;
    map <long long, long long> mapping;
    mapped[0] = -1;
    mapping[0] = -1;
    int ans = INT32_MAX;
    long long prev = 0;
    for (int i = 0; i < nums.size(); i++) {
        prev = prev + nums[i];

        auto decider = mapping.lower_bound(k - prev);

        if (decider != mapping.end()) {
            ans = min(ans, int(i - (*decider).second));
        }

        auto it = mapped.lower_bound(prev);
        auto it2 = mapping.lower_bound(-prev);
        if (it == mapped.end()) {
            ;
        } else {
            mapped.erase(it, mapped.end());
            mapping.erase(mapping.begin(), it2);}
        }

        mapped[prev] = i;
        mapping[-prev] = i;
    }

    return ans == INT32_MAX ? -1: ans;
}

int main() {
    return 0;
}