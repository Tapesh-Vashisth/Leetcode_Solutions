#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string frequencySort(string s) {
    map <char, int> freq;

    for (auto it: s) {
        freq[it]++;
    }

    vector <pair <int, char>> store;

    for (auto it: freq) {
        store.push_back({it.second, it.first});
    }

    sort(store.begin(), store.end());

    string ans;
    for (int i = store.size() - 1; i >= 0; i--) {
        for (int j = 0; j < store[i].first; j++) {
            ans.push_back(store[i].second);
        }
    }

    return ans;
}

int main() {
    return 0;
}