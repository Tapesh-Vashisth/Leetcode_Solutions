#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map <string, vector <string>> store;

    for (int i = 0; i < strs.size(); i++) {
        string hold = strs[i];
        sort(hold.begin(), hold.end());

        store[hold].push_back(strs[i]);
    }

    vector <vector <string>> ans;

    for (auto it: store) {
        ans.push_back(it.second);
    }

    return ans;
}

int main() {
    return 0;
}