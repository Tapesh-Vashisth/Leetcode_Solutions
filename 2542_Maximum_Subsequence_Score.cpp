#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static bool comparator(pair <int, int> first, pair <int, int> second) {
    if (first.second > second.second) {
        return true;
    }

    if (first.second == second.second) {
        if (first.first > second.first) {
            return true;
        }
    }


    return false;
}

long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    vector <pair <int, int>> store;
    for (int i = 0; i < nums1.size(); i++) {
        store.push_back({nums1[i], nums2[i]});
    }

    sort(store.begin(), store.end(), comparator);

    priority_queue <pair <int, int>, vector<pair <int, int>>, greater<pair <int, int>>> q;

    long long ans = 0;
    long long total = 0;
    for (int i = 0; i < k; i++) {
        if (i != k - 1) {
            q.push(store[i]);
            total += store[i].first;        
        }
    }

    ans = max(ans, (total + store[k - 1].first) * store[k - 1].second);

    for (int i = k; i < store.size(); i++) {
        if (q.size() > 0 && store[i - 1].first > q.top().first) {
            total -= q.top().first;
            total += store[i - 1].first;
            q.pop();
            q.push(store[i - 1]);
        }


        ans = max(ans, (total + store[i].first) * store[i].second);
    }

    return ans;
}

int main() {
    return 0;
}