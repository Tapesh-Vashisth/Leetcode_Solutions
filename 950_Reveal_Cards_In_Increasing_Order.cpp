#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(deck.begin(), deck.end());
    queue <int> store;

    for (int i = 0; i < deck.size(); i++) {
        store.push(i);
    }

    int current = 0;

    vector <int> ans(deck.size(), 0);

    vector <int> keep;
    while (!store.empty()) {
        int hold = store.front();
        store.pop();

        keep.push_back(hold);
        
        if (!store.empty()) {
            int temp = store.front();
            store.pop();

            store.push(temp);
        }
    }

    for (int i = 0; i < keep.size(); i++) {
        ans[keep[i]] = deck[i];
    }

    return ans;
}

int main() {
    return 0;
}