#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool check(int n, vector <vector <int>> & store) {
        vector <int> hash(n, 0);

        for (int i = 0; i < store.size(); i++) {
            hash[store[i][0]]--;
            hash[store[i][1]]++;
        }

        for (auto it: hash) {
            if (it != 0) {
                return false;
            }
        }

        return true;
}

int helper(int n, vector <vector <int>> & requests, int index, vector <vector <int>> & store) {
    if (index >= requests.size()) {
        if (check(n, store)) {
            return store.size();
        } else {
            return 0;
        }
    }

    // take
    store.push_back(requests[index]);
    int take = helper(n, requests, index + 1, store);
    store.pop_back();

    // not take 
    int nottake = helper(n, requests, index + 1, store);

    return max(take, nottake);
}

int maximumRequests(int n, vector<vector<int>>& requests) {
    vector <vector <int>> store;
    return helper(n, requests, 0, store);
}

int main() {
    return 0;
}