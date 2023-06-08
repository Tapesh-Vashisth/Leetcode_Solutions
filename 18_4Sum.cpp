#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    set <vector <int>> ans;
    for (long long i = 0; i < nums.size(); i++) {
        for (long long j = i + 1; j < nums.size(); j++) {
            long long low = j + 1;
            long long high = nums.size() - 1;

            while (low < high) {
                long long hold = (long long)nums[i] + nums[j] + nums[low] + nums[high];

                if (hold == target) {
                    ans.insert({nums[i], nums[j], nums[low], nums[high]});
                }

                if (hold > target) {
                    high--;
                } else {
                    low++;
                }
            }
        }
    }

    vector <vector <int>> store;

    for (auto it: ans) {
        store.push_back(it);
    }

    return store;
}

int main() {
    return 0;
}