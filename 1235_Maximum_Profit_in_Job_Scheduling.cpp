#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    vector <vector <int>> store;
    int n = startTime.size();

    for (int i = 0; i < n; i++) {
        store.push_back({endTime[i], startTime[i], profit[i]});
    }

    sort(store.begin(), store.end());

    map <int, int> mapped;
    int ans = 0;
    for (auto & it: store) {
        auto hold = mapped.lower_bound(-it[1]);

        int mx = 0;
        if (hold == mapped.end()) {
            ;
        } else {
            mx = (*hold).second;
        }

        ans = max(ans, mx + it[2]);

        mapped[-it[0]] = mx + it[2];
    }

    return ans;
}

int main() {
    return 0;
}