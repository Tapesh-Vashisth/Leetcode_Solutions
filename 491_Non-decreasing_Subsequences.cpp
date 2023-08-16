#include <iostream>
#include <vector>
using namespace std;   

vector <vector <int>> ans;

    void helper(vector <int> & nums, int index, vector <int> & temp) {
        if (temp.size() >= 2) {
            ans.push_back(temp);
        }

        vector <bool> hash(202, false);
        for (int i = index; i < nums.size(); i++) {
            if (hash[nums[i] + 100] == false && (temp.size() == 0 || nums[i] >= temp[temp.size() - 1])) {
                hash[nums[i] + 100] = true;
                temp.push_back(nums[i]);
                helper(nums, i + 1, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector <int> temp;
        helper(nums, 0, temp);

        return ans;
    }

int main() {
    return 0;
}