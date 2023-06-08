#include <iostream>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector <int> ans;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[nums[i] - 1] < 0) {
            ans.push_back(nums[i]);
        } else {
            nums[nums[i] - 1] = -nums[nums[i] - 1];
        }
    }

    return ans;
}


int main() {
    return 0;
}