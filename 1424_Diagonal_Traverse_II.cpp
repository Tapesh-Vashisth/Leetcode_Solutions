#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    int mx = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums[i].size(); j++) {
            mx = max(mx, i + j);
        }
    }
    vector <vector <int>> store(mx + 1);

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums[i].size(); j++) {
            store[i + j].push_back(nums[i][j]);
        }
    }

    vector <int> ans;
    for (auto & it: store) {
        reverse(it.begin(), it.end());
        for (int i = 0; i < it.size(); i++) {
            ans.push_back(it[i]);
        }
    }

    return ans;
}

int main() {
    return 0;
}