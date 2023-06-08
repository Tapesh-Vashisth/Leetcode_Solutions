#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <vector <int>> helper(vector <int>& nums, int current, vector <int> & hash) {
    vector <vector<int>> ret = {{}};
    if (current >= nums.size()) {
        return ret;
    }
    // recursion and backtracking 
    
    ret = helper(nums, current + 1, hash);
    vector <vector <int>> hold = ret;

    cout << current << endl;
    for (int i = 0; i < ret.size(); i++) {
        if (ret[i].size() == 0 && hash[nums[current] + 100] == 0) {
            ret[i].push_back(nums[current]);
            hold.push_back(ret[i]);
        } else if (ret[i].size() > 0) {

            int decider = count(ret[i].begin(), ret[i].end(), nums[current]);
            if (nums[current] <= ret[i][ret[i].size() - 1] && (nums[current + 1] != nums[current] || decider == hash[nums[current] + 100])) {
                ret[i].push_back(nums[current]);
                hold.push_back(ret[i]);
            }
        }
    }

    hash[nums[current] + 100]++;
    return hold;
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector <int> hash(205 , 0);
    vector <vector<int>> ans = helper(nums, 0, hash);

    vector <vector <int>> finalans;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i].size() > 1) {
            reverse(ans[i].begin(), ans[i].end());
            finalans.push_back(ans[i]);
        }
    }

    for (int i = 0; i < finalans.size(); i++) {
        for (int j = 0; j < finalans[i].size(); j++) {
            cout << finalans[i][j] << " ";
        }
        cout << endl;
    }

    return finalans;
}


// void helper(vector <int> & nums, int current, vector <vector <int>> &ans) {
//     vector <int> hash(nums.size(), 0);
//     vector <vector <int>> ans;
//     for (int i = current + 1; i < nums.size(); i++) { 
//         if (hash[nums[i]] == 0) {
//             if (nums[i] >= nums[current]) {
//                 vector <vector<int>> temp = helper(nums, i);
//                 for (int j = 0; j < temp.size(); j++) {
//                     ans.push_back(temp[j]);
//                 }
//             }
//             hash[nums[i]] == 1;
//         }
//     }

// }

// vector<vector<int>> findSubsequences(vector<int>& nums) {
//     vector <vector <int>> ans = helper(nums, 0);
// }

int main() {
    vector <int> x = {1,2,3,4,5,6,7,8,9,10,1,1,1,1,1};
    findSubsequences(x);
    return 0;
}

