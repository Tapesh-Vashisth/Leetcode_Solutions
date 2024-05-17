#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    map <int, int> store;

    for (int i = 0; i < arr.size(); i++) {
        store[arr[i]]++;
    }

    vector <pair <int, int>> keep;

    for (auto it: store) {
        keep.push_back({it.second, it.first});
    }

    sort(keep.begin(), keep.end());

    int index = 0;
    while (k && index < keep.size()) {
        if (k < keep[index].first) {
            k = 0;
        } else {
            k -= keep[index].first;
            index++;
        }
    }

    return keep.size() - index;
}

int main() {
    return 0;
} 