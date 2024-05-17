#include <iostream>
#include <vector>
#include <set>
using namespace std;

int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int total = 0;

    set <pair <int, int>, greater<pair <int, int>>> store;
    for (int i = 1; i < heights.size(); i++) {
        if (heights[i] > heights[i - 1]) {
            total += heights[i] - heights[i - 1];
        }

        store.insert({heights[i], i});

        // if the bricks get over 
        while (total > bricks && !store.empty() && ladders) {
            pair <int, int> hold = (*store.begin());
            store.erase(hold);
            total -= hold.first;
            ladders--;
        }

        if (total > bricks) {
            return i;
        }
    }    

    return heights.size();
}

int main() {
    return 0;
}