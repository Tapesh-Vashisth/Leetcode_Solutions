#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void helper(vector <int> & rods, int index, int sum1, int sum2, unordered_map <int, int> & store) {
    if (index >= rods.size()) {
        store[sum1 - sum2] = max(sum1, store[sum1 - sum2]);
        return ;
    }


    // first 
    helper(rods, index + 1, sum1 + rods[index], sum2, store);

    // second 
    helper(rods, index + 1, sum1, sum2 + rods[index], store);

    // nothing 
    helper(rods, index + 1, sum1, sum2, store);
}

int tallestBillboard(vector<int>& rods) {
    vector <int> first;
    vector <int> second;

    int index = 0;

    while (index < rods.size() / 2) {
        first.push_back(rods[index]);
        index++;
    }

    while (index < rods.size()) {
        second.push_back(rods[index]);
        index++;
    }


    unordered_map <int, int> firstMap;
    helper(first, 0, 0, 0, firstMap);

    unordered_map <int, int> secondMap;
    helper(second, 0, 0, 0, secondMap);

    int ans = 0;

    for (auto it: firstMap) {
        if (secondMap.find(-it.first) != secondMap.end()) {
            ans = max(ans, it.second + secondMap[-it.first]);
        }
    }

    return ans;
}

int main() {
    vector <int> store = {1, 2, 3, 4, 5, 6};
    cout << tallestBillboard(store) << endl;
    return 0;
}