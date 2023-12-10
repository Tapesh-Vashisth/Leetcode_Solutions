#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    map <int, int> store;

    store[0] = 0;

    for (auto it: flowers) {
        store[it[0]]++;
        store[it[1] + 1]--;
    }

    int move = 0;
    for (auto it: store) {
        move += it.second;
        store[it.first] = move;
    }

    vector <int> ans;

    for (auto it: people) {
        auto pos = store.lower_bound(it);
        if ((*pos).first == it) {
            ans.push_back((*pos).second);
        } else {
            ans.push_back((*(--pos)).second);
        }
    }

    return ans;
}

int main() {
    return 0;
}