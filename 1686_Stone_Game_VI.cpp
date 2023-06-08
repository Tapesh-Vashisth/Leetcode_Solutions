#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    vector <pair <int, int>> store;
    for (int i = 0; i < aliceValues.size(); i++) {
        store.push_back({aliceValues[i] + bobValues[i], i});
    }

    sort(store.begin(), store.end());

    int alice = 0;
    int bob = 0;

    for (int i = store.size() - 1; i >= 0; i--) {
        if ((store.size() - 1 - i) % 2 == 0) {
            alice += aliceValues[store[i].second];
        } else {
            bob += bobValues[store[i].second];
        }
    }

    if (bob == alice) {
        return 0;
    } else if (alice > bob) {
        return 1;
    } else {
        return -1;
    }
}

int main() {
    return 0;
}