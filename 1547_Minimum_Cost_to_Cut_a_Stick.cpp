#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    set <pair <int, int>> store;
    set <int> front;
    front.insert(0);
    front.insert(n);
    set <int> back;
    back.insert(0);
    back.insert(-n);
    unordered_map <int, int> power;

    for (int i = 1; i < cuts.size() - 1; i++) {
        store.insert({cuts[i + 1] - cuts[i - 1], cuts[i]});
        power[cuts[i]] = cuts[i + 1] - cuts[i - 1];
        front.insert(cuts[i]);
        back.insert(-cuts[i]);
    }

    int ans = 0;
    
    while (!store.empty()) {
        auto it = store.begin();
        pair <int, int> hold = (*it);
        store.erase(it);

        ans += hold.first;

        int frontele = *front.lower_bound(hold.second + 1);
        int backele = *back.lower_bound(-hold.second + 1);
        front.erase(hold.second);
        back.erase(hold.second);
        
        int fronthold = power[frontele];
        int backhold = power[backele];

        power[frontele] += hold.second - backele;
        power[backele] += frontele - hold.second;

        auto frontit = store.find({fronthold, frontele});
        auto backit = store.find({backhold, backele});

        store.erase(frontit);
        store.erase(backit);

        store.insert({power[frontele], frontele});
        store.insert({power[backele], backele});
    }

    return ans;
}

int helper(vector <int> & cuts, int l, int r) {
    if (r <= l) {
        return 0;
    } 

    int mn = INT32_MAX;

    for (int i = 0; i < cuts.size(); i++) {
        if (cuts[i] > l && cuts[i] < r) {
            int left = helper(cuts, l, cuts[i]);
            int right = helper(cuts, cuts[i], r);

            mn = min(mn, left + right + (l - r));
        }
    }

    return mn;
}

int minCost(int n, vector<int>& cuts) {
    return helper(cuts, 0, n);
}

int main() {
    return 0;
}