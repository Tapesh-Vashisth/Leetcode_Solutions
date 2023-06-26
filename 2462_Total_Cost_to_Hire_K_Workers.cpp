#include <iostream>
#include <vector>
#include <set>
using namespace std;
 
long long totalCost(vector<int>& costs, int k, int candidates) {
    set <pair <int, int>> store;
    for (int i = 0; i < candidates; i++) {
        store.insert({costs[i], i});
        store.insert({costs[costs.size() - i - 1], costs.size() - i - 1});
    }

    int low = candidates;
    int high = costs.size() - candidates - 1;
    long long ans = 0;
    for (int i = 0; i < k; i++) {
        if (store.size() > 0) {
            auto lowest = store.begin();
            pair <int, int> hold = (*lowest);
            store.erase(lowest);

            ans += hold.first;

            if (low <= high) {
                if (hold.second < low) {
                    store.insert({costs[low], low});
                    low++;
                } else if (hold.second > high) {
                    store.insert({costs[high], high});
                    high--;
                }
            }
        }
    }

    return ans;
}

int main() {

    return 0;
}