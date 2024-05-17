#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


static bool comp(pair <int, int> first, pair <int, int> second) {
    return (first.first * second.second) <= (second.first * first.second); 
}

vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    vector <pair <int, int>> store;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            store.push_back({arr[i], arr[j]});
        }
    }

    sort(store.begin(), store.end(), comp);


    vector <int> ans = {store[k - 1].first, store[k - 1].second};
    return ans;        
}

int main() {
    return 0;
}