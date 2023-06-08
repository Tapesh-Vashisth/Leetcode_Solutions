#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    multiset <int> store;
    for (auto it: candies) {
        store.insert(it);
    }

    vector <bool> ans;

    for (int i = 0; i < candies.size(); i++) {
        store.insert(candies[i] + extraCandies);

        if (*(--store.end()) == candies[i] + extraCandies) {
            ans.push_back(true);
        } else {
            ans.push_back(false);
        }

        int counter = store.erase(candies[i] + extraCandies);

        for (int j = 0; j < counter - 1; j++) {
            store.insert(candies[i] + extraCandies);
        }
    }

    return ans;
}

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector <bool> ans;
    int mx = INT32_MIN;
    for (auto & it: candies) {
        mx = max(it, mx);     
    }       

    for (auto it: candies) {
        int hold = it + extraCandies;

        if (hold >= mx) {
            ans.push_back(true);
        } else {
            ans.emplace_back(false);
        }
    }

    return ans;
}


int main() {
    return 0;
}