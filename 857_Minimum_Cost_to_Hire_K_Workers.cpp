#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    vector <pair <int, int>> store;        
    double ans = INT32_MAX;

    for (int i = 0; i < quality.size(); i++) {
        store.push_back({quality[i], wage[i]});
    }

    sort(store.begin(), store.end());
    priority_queue <pair <double, pair <int, int>>> keep;

    int currentQuality = 0;
    for (int i = 0; i < k; i++) {
        keep.push({((double)store[i].second)/store[i].first, store[i]});
        currentQuality += store[i].first;
    }

    pair <double, pair <int, int>> hold = keep.top();

    ans = min(ans, (double)hold.second.second + (currentQuality - hold.second.first) * hold.first);

    for (int i = k; i < store.size(); i++) {
        pair <double, pair <int, int>> hold = keep.top();

        double check = (double)store[i].second/store[i].first;

        if (check < hold.first) {
            keep.pop();
            currentQuality -= hold.second.first;
            keep.push({((double)store[i].second)/store[i].first, store[i]});
            currentQuality += store[i].first;
            hold = keep.top();
            ans = min(ans, (double)hold.second.second + ((currentQuality - hold.second.first) * hold.first));  
        }
    }

    return ans;
}

int main() {
    return 0;
}