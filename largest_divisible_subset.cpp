#include <bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector <vector <int>> answers(n, vector <int>());

    for (int i = 0; i < n; i++) {
        answers[i].push_back(nums[i]);
    }

    for(int i = 0; i < n; i++) {
        vector <int> temp = {};
        for(int j = i - 1; j >= 0; j--) {
            if (nums[i] % nums[j] == 0) {
                if (answers[j].size() > temp.size()) {
                    temp = answers[j];
                }
            }
        }

        answers[i].insert(answers[i].end(), temp.begin(), temp.end());
    }

    int mx = 0;
    for (int i = 1; i < n; i++) {
        if (answers[i].size() > answers[mx].size()) {
            mx = i;
        }
    }

    return answers[mx];
}

int main() {
    return 0;
}