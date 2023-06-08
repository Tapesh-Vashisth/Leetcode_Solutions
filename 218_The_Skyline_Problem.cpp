#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector <vector <int>> ans;

    unordered_map <int, vector <pair <int, int>>> store;
    for (int i = 0; i < buildings.size(); i++) {
        store[buildings[i][0]].push_back({buildings[i][2], i});
        store[buildings[i][1]].push_back({buildings[i][2], i});
    }

    vector <bool> taken(buildings.size(), false);

    set <pair <int, int>> container = {0, -1};

    int prev = 0;
    for (auto it: store) {
        for (int i = 0; i < it.second.size(); i++) {
            if (taken[it.second[i].second] == false) {
                container.insert(it.second[i]);
                taken[it.second[i].second] = true;
            } else {
                container.erase(it.second[i]);
            }
        }

        if ((*container.begin()).first != prev) {
            ans.push_back({it.first, (*container.begin()).first});
        }

        prev = (*container.begin()).first;
    }

    return ans;
}   

int main() {
    return 0;
}